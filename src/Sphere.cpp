/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-william.niarquin
** File description:
** Sphere
*/

#include "Sphere.hpp"

// Getters
const Vector3D& Sphere::getCenter() const
{
    return _center;
}

const double& Sphere::getRadius() const
{
    return _radius;
}



// Setters

void Sphere::setCenter(const Vector3D& center)
{
    _center = center;
}

void Sphere::setRadius(const double& radius)
{
    _radius = radius;
}
