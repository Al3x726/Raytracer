/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-william.niarquin
** File description:
** Cone
*/

#include "../inc/Cone.hpp"


// constructor

Cone::Cone(const Vector3D &position, const Vector3D &direction, float radius, float height, Color color)
    : _position(position), _direction(direction), _radius(radius), _height(height), _color(color)
{}

// getters

Vector3D Cone::getPosition() const
{ return _position; }

Vector3D Cone::getDirection() const
{ return _direction; }

float Cone::getRadius() const
{ return _radius; }

float Cone::getHeight() const
{ return _height; }


// Setters

void Cone::setPosition(const Vector3D &position)
{ _position = position; }

void Cone::setDirection(const Vector3D &direction)
{ _direction = direction; }

void Cone::setRadius(float radius)
{ _radius = radius; }

void Cone::setHeight(float height)
{ _height = height; }


// Methods

// [intersect] method that checks if a ray intersects with the cone
bool Cone::intersect(const Ray &ray, float &t) const
{
    float a = ray.getDirection().getX()*ray.getDirection().getX() + ray.getDirection().getY()*ray.getDirection().getY() - ray.getDirection().getZ()*ray.getDirection().getZ()*(_radius*_radius / _height/_height);
    float b = 2*(ray.getOrigin().getX()*ray.getDirection().getX() + ray.getOrigin().getY()*ray.getDirection().getY() - ray.getDirection().getZ()*ray.getDirection().getZ()*(_radius*_radius / _height/_height)*(ray.getOrigin().getZ() - _position.getZ()) - _position.getX()*ray.getDirection().getX() - _position.getY()*ray.getDirection().getY() + ray.getDirection().getZ()*(_radius*_radius / _height)*(ray.getOrigin().getZ() - _position.getZ()));
    float c = ray.getOrigin().getX()*ray.getOrigin().getX() + ray.getOrigin().getY()*ray.getOrigin().getY() - (_radius*_radius / _height)*(ray.getOrigin().getZ() - _position.getZ())*(ray.getOrigin().getZ() - _position.getZ()) - 2*(_position.getX()*ray.getOrigin().getX() + _position.getY()*ray.getOrigin().getY() - ray.getDirection().getZ()*(_radius*_radius / _height)*(ray.getOrigin().getZ() - _position.getZ())*_position.getZ()) + _position.getX()*_position.getX() + _position.getY()*_position.getY() - (_radius*_radius / _height)*_position.getZ()*_position.getZ();

    // Solve the quadratic equation
    float discriminant = b*b - 4*a*c;
    if (discriminant < 0) {
        // No real solutions
        return false;
    } else {
        float t1 = (-b + sqrt(discriminant)) / (2*a);
        float t2 = (-b - sqrt(discriminant)) / (2*a);

        if (t1 >= 0 || t2 >= 0) {
            t = std::min(t1, t2);
            // At least one solution is positive, meaning the ray intersects the cone
            return true;
        } else {
            // One solution is negative, meaning the intersection is behind the ray origin
            return false;
        }
    }
}

Vector3D Cone::normalize() const
{
    this->_direction.normalize();
    return this->_direction;
}

Vector3D Cone::getNormal(const Vector3D &intersection) const
{
    Vector3D normal = intersection - _position;
    normal.normalize();
    return normal;
}

const Color &Cone::getColor() const
{
    return _color;
}
