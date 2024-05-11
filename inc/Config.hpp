/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-william.niarquin
** File description:
** Config
*/

#pragma once

#ifndef CONFIG_HPP_
    #define CONFIG_HPP_

    #include "raytracer.hpp"
    #include "RaySetting.hpp"
    #include "Light.hpp"
    #include "Vector3D.hpp"
    #include "Color.hpp"
    #include "Sphere.hpp"
    #include "Plane.hpp"
    #include "Camera.hpp"
    #include "Cone.hpp"
    #include "Cylinder.hpp"


/**
 * @brief [Config] class of the config
 * This class is used to define the config of the raytracer method factory
 * and thiw class use the libconfig library to parse the config file
 * and to define the methods that the config must have
 * (ex: getRaySetting, ...)
 * 
 * @attention the config file must be in the format of the libconfig library and install the libconfig library
 * 
 * @param _config: the config (libconfig::Config)
 */
class Config {
    public:

        /**
         * @brief Construct a new Config object
         * 
         * @param path name of the config file
         */
        Config(const char *path);

        /**
         * @brief Destroy the Config object
         */
        ~Config() = default;



        /**
         * @brief Get the Ray Setting object by name (ex: "Camera", "Light")
         * 
         * @param name of the ray setting
         * @return RaySetting*
         */
        RaySetting* getRaySetting(const std::string name);

        /**
         * @brief Get the Ray Setting object (ex: "Iprimitives")
         * 
         * @return std::vector<Iprimitives *>* 
         */
        std::vector<Iprimitives *> *getRaySetting();

    private:

        /**
         * @brief Get the Material object by name (ex: "Camera", "Light")
         * 
         * @param name of the material
         * @return RaySetting*
         */
        RaySetting* getMaterial(const std::string name);

        /**
         * @brief Get the Camera object
         * 
         * @param setting of the camera
         * @return RaySetting* 
         */
        RaySetting* getCamera(libconfig::Setting& setting);

        /**
         * @brief Get the Light object
         * 
         * @param setting of the light
         * @return RaySetting* 
         */
        RaySetting* getLight(libconfig::Setting& setting);

        /**
         * @brief Get the Sphere object
         * 
         * @param setting of the sphere
         * @return Sphere 
         */
        Sphere getSphere(libconfig::Setting& setting);

        /**
         * @brief Get the Plane object
         * 
         * @param setting of the plane
         * @return Plane 
         */
        Plane getPlane(libconfig::Setting& setting);

        /**
         * @brief Get the Cylinder object
         * 
         * @param setting of the cylinder
         * @return Cylinder 
         */
        Cylinder getCylinder(libconfig::Setting& setting);

        /**
         * @brief Get the Color object
         * 
         * @param setting of the color
         * @return Color 
         */
        Color getColor(libconfig::Setting& setting);

        /**
         * @brief Get the Vector3 D object
         * 
         * @param setting of the vector3D
         * @return Vector3D 
         */
        Vector3D getVector3D(libconfig::Setting& setting);

        /**
         * @brief Get the Cone object
         * 
         * @param setting of the cone
         * @return Cone 
         */
        Cone getCone(libconfig::Setting& setting);


        libconfig::Config _config;
};

#endif /* !CONFIG_HPP_ */
