/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-william.niarquin
** File description:
** Light
*/

#include "Light.hpp"


// Operators

Light& Light::operator+=(const Light& other)
{
    for (size_t i = 0; other._pointLights.size() > i; i++)
        _pointLights.push_back(other._pointLights[i]);
    for (size_t i = 0; other._directionalLights.size() > i; i++)
        _directionalLights.push_back(other._directionalLights[i]);
    _ambient = _ambient + other._ambient / 2;
    _diffuse = _diffuse + other._diffuse / 2;
    return *this;
}

Light& Light::operator-=(const Light& other)
{
    for (size_t i = 0; other._pointLights.size(); i++)
        _pointLights.erase(std::remove(_pointLights.begin(), _pointLights.end(), other._pointLights[i]), _pointLights.end());
    for (size_t i = 0; other._directionalLights.size(); i++)
        _directionalLights.erase(std::remove(_directionalLights.begin(), _directionalLights.end(), other._directionalLights[i]), _directionalLights.end());
    return *this;
}

Light Light::operator+(const Light& other) const
{
    Light tmp(*this);
    tmp += other;
    return tmp;
}

Light Light::operator-(const Light& other) const
{
    Light tmp(*this);
    tmp -= other;
    return tmp;
}

bool Light::operator==(const Light& other) const
{ return _ambient == other._ambient && _diffuse == other._diffuse && _pointLights == other._pointLights && _directionalLights == other._directionalLights; }

bool Light::operator!=(const Light& other) const
{ return !(*this == other); }


// Getters

double Light::getAmbient() const
{ return _ambient; }

double Light::getDiffuse() const
{ return _diffuse; }

const std::vector<Vector3D>& Light::getPointLights() const
{ return _pointLights; }

const std::vector<Vector3D>& Light::getDirectionalLights() const
{ return _directionalLights; }


// Setters

void Light::setAmbient(double ambient)
{ _ambient = ambient; }

void Light::setDiffuse(double diffuse)
{ _diffuse = diffuse; }

void Light::setPointLights(const std::vector<Vector3D>& pointLights)
{ _pointLights = pointLights; }

void Light::setDirectionalLights(const std::vector<Vector3D>& directionalLights)
{ _directionalLights = directionalLights; }


// Adders

void Light::addPointLight(const Vector3D& pointLight)
{ _pointLights.push_back(pointLight); }

void Light::addDirectionalLight(const Vector3D& directionalLight)
{ _directionalLights.push_back(directionalLight); }


// Methods

void Light::clear()
{
    _ambient = 0;
    _diffuse = 0;
    _pointLights.clear();
    _directionalLights.clear();
}

Color Light::getColor(const Vector3D &point, const Vector3D &normal, Color &color) const
{
    Color tmpColor = color;
    for (size_t i = 0; _pointLights.size() > i; i++) {
        Vector3D lightDir = _pointLights[i] - point;
        double distance = lightDir.length();
        lightDir.normalize();
        double diff = std::max<float>(normal.dot(lightDir), 0.0);
        tmpColor += color * diff / distance;
    }
    for (size_t i = 0; _directionalLights.size() > i; i++) {
        Vector3D lightDir = _directionalLights[i];
        double distance = lightDir.length();
        lightDir.normalize();
        double diff = std::max<float>(normal.dot(lightDir), 0.0);
        tmpColor += color * diff / distance;
    }
    return tmpColor;
}
