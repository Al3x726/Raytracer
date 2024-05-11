/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-william.niarquin
** File description:
** Plane
*/

#include "Plane.hpp"

// Constructors

Plane::Plane(const int &axis, const double &position, const Color &color)
{
    _axis = axis;
    _position = position;
    _color = color;
    _a = _axis == 0 ? 1 : 0;
    _b = _axis == 1 ? 1 : 0;
    _c = _axis == 2 ? 1 : 0;
    _d = -_position;
}


// Getters

int Plane::getAxis() const
{ return _axis; }

double Plane::getPosition() const
{ return _position; }

const Color &Plane::getColor() const
{ return _color; }


// Setters

void Plane::setAxis(const int &axis)
{
    _axis = axis;
    _a = _axis == 0 ? 1 : 0;
    _b = _axis == 1 ? 1 : 0;
    _c = _axis == 2 ? 1 : 0;
}

void Plane::setPosition(const double &position)
{
    _position = position;
    _d = -_position;
}

void Plane::setColor(const Color &color)
{ _color = color; }


// Methods

bool Plane::intersect(const Ray& ray, float& t) const
{
    t = -(_a * ray.getOrigin().getX() + _b * ray.getOrigin().getY() + _c * ray.getOrigin().getZ() + _d) / (_a * ray.getDirection().getX() + _b * ray.getDirection().getY() + _c * ray.getDirection().getZ());
    if (t < 0)
        return false;
    return true;
}

Vector3D Plane::normalize() const
{
    double x = _axis == 0 ? 1 : 0;
    double y = _axis == 1 ? 1 : 0;
    double z = _axis == 2 ? 1 : 0;
    return Vector3D(x, y, z);
}

Vector3D Plane::getNormal(const Vector3D& intersectionPoint) const
{ return normalize(); (void)intersectionPoint; }
