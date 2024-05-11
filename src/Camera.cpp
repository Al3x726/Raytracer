/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-william.niarquin
** File description:
** Camera
*/

#include "Camera.hpp"

Camera::Camera(Vector3D position, Vector3D rotation, double fov, sf::Vector2i resolution) : _position(position), _rotation(rotation), _fov(fov), _resolution(resolution)
{
    _rotation.normalize();
    _up = Vector3D(0, 1, 0);
    _up.normalize();

    Vector3D direction = _rotation - _position;
    direction.normalize();
    _right = direction.cross(_up);
    _right.normalize();
}

Vector3D Camera::getPosition() const
{
    return this->_position;
}

Vector3D Camera::getRotation() const
{
    return this->_rotation;
}

double Camera::getFov() const
{
    return this->_fov;
}

sf::Vector2i Camera::getResolution() const
{
    return this->_resolution;
}

std::vector<Color> Camera::getPixels() const
{
    return this->_pixels;
}

Color Camera::getPixel(int x, int y) const
{
    return this->_pixels.at(y * this->_resolution.x + x);
}

Color Camera::getPixel(int index) const
{
    return this->_pixels.at(index);
}

void Camera::setPosition(Vector3D position)
{
    this->_position = position;
}

void Camera::setRotation(Vector3D rotation)
{
    this->_rotation = rotation;
}

void Camera::setFov(double fov)
{
    this->_fov = fov;
}

void Camera::setResolution(sf::Vector2i resolution)
{
    this->_resolution = resolution;
}

void Camera::setPixels(std::vector<Color> pixels)
{
    this->_pixels = pixels;
}

void Camera::setPixel(int x, int y, Color color)
{
    this->_pixels.at(y * this->_resolution.x + x) = color;
}

void Camera::setPixel(int index, Color color)
{
    this->_pixels.at(index) = color;
}

// getRay returns a ray from the camera to the pixel (x, y) on the screen (z = 0)
// \param x: x coordinate of the pixel on the screen (width) (0 to width - 1)
// \param y: y coordinate of the pixel on the screen (height) (0 to height - 1)
// \return: a ray from the camera to the pixel (x, y) on the screen (z = 0)
Ray Camera::getRay(float x, float y) const
{
    float px = (2.0f * x) / _resolution.x - 1.0f;
    float py = 1.0f - (2.0f * (y + ((_resolution.x / 2) -(_resolution.y / 2)))) / _resolution.x;
    
    // Calcul de la distance focale en fonction du champ de vision
    // float d = 1.0f / std::tan(_fov * 0.5f * M_PI / 180.0f);
    
    // Calcul de la direction du rayon
    Vector3D direction = Vector3D(px, 1, py).normalize();

    // Application de la rotation à la direction du rayon
    // direction.rotateX(_rotation.getX());
    // direction.rotateY(_rotation.getY());
    // direction.rotateZ(_rotation.getZ());

    return Ray(_position, direction);
}
