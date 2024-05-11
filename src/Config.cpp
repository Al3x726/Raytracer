/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-william.niarquin
** File description:
** Config
*/

#include "Config.hpp"

Config::Config(const char *path)
{
    try {
        this->_config.readFile(path);
    } catch(const libconfig::FileIOException &fioex) {
        std::cerr << "Erreur lors de la lecture du fichier de configuration." << std::endl;
        exit(84);
    } catch(const libconfig::ParseException &pex) {
        std::cerr << "Erreur lors de l'analyse du fichier de configuration à la ligne " 
                  << pex.getLine() << ": " << pex.getError() << std::endl;
        exit(84);
    }
}

RaySetting* Config::getRaySetting(const std::string name) {
    if (this->_config.exists(name))
        return this->getMaterial(name);
    else
        throw std::invalid_argument("Le paramètre " + name + " n'existe pas dans le fichier de configuration.");
}

std::vector<Iprimitives *> *Config::getRaySetting()
{
    std::vector<Iprimitives *> *primitives = new std::vector<Iprimitives *>;

    try {
        libconfig::Setting &setting = _config.lookup("primitives");
        if (setting.exists("spheres")) {
            for (int i = 0; i < setting["spheres"].getLength(); i++) {
                Sphere *sphere = new Sphere(this->getSphere(setting["spheres"][i]));
                primitives->push_back(sphere);
            }
        }
        if (setting.exists("planes")) {
            for (int i = 0; i < setting["planes"].getLength(); i++) {
                Plane *plane = new Plane(this->getPlane(setting["planes"][i]));
                primitives->push_back(plane);
            }
        }
        if (setting.exists("cones")) {
            for (int i = 0; i < setting["cones"].getLength(); i++) {
                Cone *cone = new Cone(this->getCone(setting["cones"][i]));
                primitives->push_back(cone);
            }
        }
        if (setting.exists("cylinders")) {
            for (int i = 0; i < setting["cylinders"].getLength(); i++) {
                Cylinder *cylinder = new Cylinder(this->getCylinder(setting["cylinders"][i]));
                primitives->push_back(cylinder);
            }
        }
    } catch (const libconfig::SettingTypeException &nfex) {
        std::cerr << "Erreur lors de la lecture du fichier de configuration." << std::endl;
        exit(84);
    }
    return (primitives);
}

RaySetting* Config::getMaterial(const std::string name)
{
    if (name == "camera")
        return this->getCamera(_config.lookup(name));
    else if (name == "lights")
        return this->getLight(_config.lookup(name));
    else
        throw std::invalid_argument("Le type " + name + " n'existe pas dans le fichier de configuration.");
}

RaySetting *Config::getLight(libconfig::Setting &setting)
{
    RaySetting *light;

    try {
        float ambient = setting["ambient"];
        float diffuse = setting["diffuse"];
        std::vector<Vector3D> positions;
        std::vector<Vector3D> directionals;
        for (int i = 0; i < setting["point"].getLength(); i++) {
            Vector3D position = this->getVector3D(setting["point"][i]);
            positions.push_back(position);
        }
        for (int i = 0; i < setting["directional"].getLength(); i++) {
            Vector3D directional = this->getVector3D(setting["directional"][i]);
            directionals.push_back(directional);
        }
        light = new Light(ambient, diffuse, positions, directionals);
    } catch (const libconfig::SettingTypeException &nfex) {
        std::cerr << "Erreur lors de la lecture du fichier de configuration." << std::endl;
        exit(84);
    }
    return (light);
}

RaySetting* Config::getCamera(libconfig::Setting& setting)
{
    RaySetting *camera;

    try {
        Vector3D position = this->getVector3D(setting["position"]);
        Vector3D rotation = this->getVector3D(setting["rotation"]);
        sf::Vector2i resolution(setting["resolution"]["width"], setting["resolution"]["height"]);
        double fov = setting["fieldOfView"];
        camera = new Camera(position, rotation, fov, resolution);
    } catch (const libconfig::SettingTypeException &nfex) {
        std::cerr << "Erreur lors de la lecture du fichier de configuration." << std::endl;
        exit(84);
    }
    return (camera);
}

Plane Config::getPlane(libconfig::Setting &setting)
{
    Plane plane;

    try {
        int nbAxis;
        std::string axis = setting["axis"];
        switch (axis[0]) {
            case 'X':
                nbAxis = 0;
                break;
            case 'Y':
                nbAxis = 1;
                break;
            case 'Z':
                nbAxis = 2;
                break;
            default:
                throw std::invalid_argument("L'axe " + axis + " n'existe pas.");
        }
        int position = setting["position"];
        Color color = this->getColor(setting["color"]);
        plane = Plane(nbAxis, position, color);
    } catch (const libconfig::SettingTypeException &nfex) {
        std::cerr << "Erreur lors de la lecture du fichier de configuration. (Plane)" << std::endl;
        exit(84);
    }
    return (plane);
}

Cylinder Config::getCylinder(libconfig::Setting &setting)
{
    Cylinder cylinder;

    try {
        Vector3D position = this->getVector3D(setting);
        Vector3D direction = this->getVector3D(setting["direction"]);
        int radius = setting["radius"];
        int height = setting["height"];
        Color color = this->getColor(setting["color"]);
        cylinder = Cylinder(position, direction, radius, height, color);
    } catch (const libconfig::SettingTypeException &nfex) {
        std::cerr << "Erreur lors de la lecture du fichier de configuration. (Cylinder)" << std::endl;
        exit(84);
    }
    return (cylinder);
}

Sphere Config::getSphere(libconfig::Setting &setting)
{
    Sphere sphere;

    try {
        Vector3D position = this->getVector3D(setting);
        int radius = setting["r"];
        Color color = this->getColor(setting["color"]);
        sphere = Sphere(position, radius, color);
    } catch (const libconfig::SettingTypeException &nfex) {
        std::cerr << "Erreur lors de la lecture du fichier de configuration. (Sphere)" << std::endl;
        exit(84);
    }
    return (sphere);
}

Vector3D Config::getVector3D(libconfig::Setting &setting)
{
    int x;
    int y;
    int z;

    try {
        x = setting["x"];
        y = setting["y"];
        z = setting["z"];
    } catch (const libconfig::SettingTypeException &nfex) {
        std::cerr << "Erreur lors de la lecture du fichier de configuration. (Vector3D)" << std::endl;
        exit(84);
    }
    return Vector3D(x, y, z);
}

Color Config::getColor(libconfig::Setting &setting)
{
    int r;
    int g;
    int b;

    try {
        r = setting["r"];
        g = setting["g"];
        b = setting["b"];
    } catch (const libconfig::SettingTypeException &nfex) {
        std::cerr << "Erreur lors de la lecture du fichier de configuration. (Color)" << std::endl;
        exit(84);
    }
    return Color(r, g, b);
}

Cone Config::getCone(libconfig::Setting &setting)
{
    Cone cone;

    try {
        Vector3D position = this->getVector3D(setting["position"]);
        Vector3D direction = this->getVector3D(setting["direction"]);
        int radius = setting["radius"];
        int height = setting["height"];
        Color color = this->getColor(setting["color"]);
        cone = Cone(position, direction, radius, height, color);
    } catch (const libconfig::SettingTypeException &nfex) {
        std::cerr << "Erreur lors de la lecture du fichier de configuration. (Cone)" << std::endl;
        exit(84);
    }
    return (cone);
}
