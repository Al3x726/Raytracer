/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-william.niarquin
** File description:
** Ray
*/

#include "Ray.hpp"

Ray::Ray() : _origin(Vector3D()), _direction(Vector3D())
{
}

Ray::Ray(const Vector3D& origin, const Vector3D& direction) : _origin(origin), _direction(direction)
{
}

const Vector3D& Ray::getOrigin() const
{
    return _origin;
}

const Vector3D& Ray::getDirection() const
{
    return _direction;
}

void Ray::setOrigin(const Vector3D& origin)
{
    _origin = origin;
}

void Ray::setDirection(const Vector3D& direction)
{
    _direction = direction;
}

Ray::Ray(Ray &&other)
{
    _origin = std::move(other._origin);
    _direction = std::move(other._direction);
}

Ray &Ray::operator=(Ray &&other)
{
    if (this != &other) {
        _origin = std::move(other._origin);
        _direction = std::move(other._direction);
    }
    return *this;
}
