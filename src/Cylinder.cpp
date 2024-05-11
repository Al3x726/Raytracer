/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-william.niarquin
** File description:
** Cylinder
*/

#include "Cylinder.hpp"

// [Cylinder] constructor with parameters

Cylinder::Cylinder(const Vector3D &position, const Vector3D &direction, float radius, float height, Color color) : _radius(radius), _height(height), _color(color)
{
    _position = position;
    _direction = direction;
    _direction.normalize();    
}


// Getters

Vector3D Cylinder::getPosition() const
{ return _position; }

float Cylinder::getRadius() const
{ return _radius; }

float Cylinder::getHeight() const
{ return _height; }

const Color &Cylinder::getColor() const
{ return _color; }


// Setters

void Cylinder::setPosition(const Vector3D &position)
{ _position = position; }

void Cylinder::setRadius(float radius)
{ _radius = radius; }

void Cylinder::setHeight(float height)
{ _height = height; }


// Methods

Vector3D Cylinder::getNormal(const Vector3D &intersection) const
{
    Vector3D normal = intersection - _position;
    normal.setZ(0);
    return normal;
}

bool Cylinder::intersect(const Ray &ray, float &t) const
{
    float a = pow(ray.getDirection().getX(), 2) + pow(ray.getDirection().getY(), 2);
    float b = 2 * (ray.getDirection().getX() * (ray.getOrigin().getX() - _position.getX()) + ray.getDirection().getY() * (ray.getOrigin().getY() - _position.getY()));
    float c = pow(ray.getOrigin().getX() - _position.getX(), 2) + pow(ray.getOrigin().getY() - _position.getY(), 2) - pow(_radius, 2);
    float delta = pow(b, 2) - 4 * a * c;

    if (delta < 0) return false;

    float t1 = (-b - sqrt(delta)) / (2 * a);
    float t2 = (-b + sqrt(delta)) / (2 * a);

    if (t1 < 0 && t2 < 0) return false;

    if (t1 < 0) t = t2;
    else if (t2 < 0) t = t1;
    else t = std::min(t1, t2);
    
    Vector3D hit_point = ray.getOrigin() + ray.getDirection() * t;
    float z = hit_point.getZ() - _position.getZ();
    if (z >= 0 && z <= _height) {
        return true;
    }
    
    float t_cap1 = (_position.getZ() - ray.getOrigin().getZ()) / ray.getDirection().getZ();
    if (t_cap1 > 0) {
        Vector3D cap_hit_point = ray.getOrigin() + ray.getDirection() * t_cap1;
        float dist_to_center = sqrt((cap_hit_point.getX() - _position.getX()) * (cap_hit_point.getX() - _position.getX()) + (cap_hit_point.getY() - _position.getY()) * (cap_hit_point.getY() - _position.getY()));
        if (dist_to_center <= _radius) {
            return true;
        }
    }

    float t_cap2 = (_position.getZ() + _height - ray.getOrigin().getZ()) / ray.getDirection().getZ();
    if (t_cap2 > 0) {
        Vector3D cap_hit_point = ray.getOrigin() + ray.getDirection() * t_cap2;
        float dist_to_center = sqrt((cap_hit_point.getX() - _position.getX()) * (cap_hit_point.getX() - _position.getX()) + (cap_hit_point.getY() - _position.getY()) * (cap_hit_point.getY() - _position.getY()));
        if (dist_to_center <= _radius) {
            return true;
        }
    }
    return false;
}

Vector3D Cylinder::normalize() const
{
    return Vector3D();
}
