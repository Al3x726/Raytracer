/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-william.niarquin
** File description:
** Scene
*/

#include "Scene.hpp"

// Getters

std::vector<Iprimitives* >* Scene::getIprimitives() const
{ return _primitives; }

Light Scene::getLight() const
{ return _light; }

Camera Scene::getCamera() const
{ return _camera; }


// Setters

void Scene::setIprimitives(std::vector<Iprimitives* >* primitives)
{ _primitives = primitives; }

void Scene::setLight(Light light)
{ _light = light; }

void Scene::setCamera(Camera camera)
{ _camera = camera; }


// Methods

void Scene::addPrimitive(Iprimitives* primitive)
{ _primitives->push_back(primitive); }

bool Scene::intersect(const Ray &ray, Vector3D &intersection, Vector3D &normal, Color &color) const
{
    float t = 0;
    float tmin = 1000000;
    bool intersect = false;

    for (auto primitive : *_primitives) {
        if (primitive->intersect(ray, t) && (t < tmin)) {
            tmin = t;
            intersection = ray.getOrigin() + ray.getDirection() * t;
            color = primitive->getColor();
            normal = primitive->getNormal(intersection);
            intersect = true;
        }
    }
    return intersect;
}

bool Scene::intersect(const Ray &ray, Vector3D &intersection) const
{
    float t = 0;
    float tmin = 1000000;
    bool intersect = false;

    for (auto primitive : *_primitives) {
        if (primitive->intersect(ray, t) && (t < tmin)) {
            tmin = t;
            intersection = ray.getOrigin() + ray.getDirection() * t;
            intersect = true;
        }
    }
    return intersect;
}

Color Scene::trace(const Ray &ray, int depth) const
{
    Vector3D intersection;
    Vector3D normal;
    Color color;
    if (depth > 5 || !intersect(ray, intersection))
        return Color(0, 0, 0);
    if (intersect(ray, intersection, normal, color)) {
        color = _light.getColor(intersection, normal, color);
        // shadow
        Vector3D shadowIntersection;
        Vector3D shadowNormal;
        Color shadowColor;
        for (size_t i = 0; i < _light.getPointLights().size(); i++) {
            Ray shadowRay(intersection, _light.getPointLights().at(i) - intersection);
            if (intersect(shadowRay, shadowIntersection, shadowNormal, shadowColor)) {
                color = color * 0.7;
            }
        }
        return color;
    }
    return Color(0, 0, 0);
}

void Scene::render(ImagePPM& image) const
{
    for (int y = 0; y < image.getHeight(); y++) {
        for (int x = 0; x < image.getWidth(); x++) {
            putRendering(x, y, image.getWidth(), image.getHeight());
            Ray ray = _camera.getRay(x, y);
            Color *color = new Color();
            float r = 0;
            float g = 0;
            float b = 0;
            for (int i = 0; i < 2; i++) {
                Color color = trace(ray, 0);
                r += color.getR();
                g += color.getG();
                b += color.getB();
            }
            r /= 2;
            g /= 2;
            b /= 2;
            color->setR(r);
            color->setG(g);
            color->setB(b);
            image.setPixel(0, 0, color);
        }
    }
}

void Scene::putRendering(int x, int y, int width, int height) const
{
    float t = (float)(x + y * width) / (float)(width * height) * 100;
    if (t == 0) std::cout << "[Rendering]: " << t << "%" << std::endl;
    if (t == 10) std::cout << "[Rendering]: " << t << "%" << std::endl;
    if (t == 20) std:: cout << "[Rendering]: " << t << "%" << std::endl;
    if (t == 30) std:: cout << "[Rendering]: " << t << "%" << std::endl;
    if (t == 40) std:: cout << "[Rendering]: " << t << "%" << std::endl;
    if (t == 50) std:: cout << "[Rendering]: " << t << "%" << std::endl;
    if (t == 60) std:: cout << "[Rendering]: " << t << "%" << std::endl;
    if (t == 70) std:: cout << "[Rendering]: " << t << "%" << std::endl;
    if (t == 80) std:: cout << "[Rendering]: " << t << "%" << std::endl;
    if (t == 90) std:: cout << "[Rendering]: " << t << "%" << std::endl;
    if (t > 99.99995) std:: cout << "[Rendering]: " << 100 << "%" << std::endl;
}
