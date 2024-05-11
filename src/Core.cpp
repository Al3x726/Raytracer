/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-william.niarquin
** File description:
** Core
*/

#include "Core.hpp"
#include "Ray.hpp"
#include "fstream"

Core::Core(const char *path) : _config(path)
{
    this->_camera = static_cast<Camera *>(_config.getRaySetting("camera"));
    this->_light = static_cast<Light *>(_config.getRaySetting("lights"));
    this->_primitives = _config.getRaySetting();
    this->_image.setSize(this->_camera->getResolution().x, this->_camera->getResolution().y);
    this->_scene.setCamera(*this->_camera);
    this->_scene.setLight(*this->_light);
    this->_scene.setIprimitives(this->_primitives);
    
    this->_scene.render(this->_image);
    this->_image.createImage(path);
}

Core::~Core()
{
    delete this->_camera;
    delete this->_light;
    for (size_t i = 0; i < this->_primitives->size(); i++) {
        delete this->_primitives->at(i);
    }
    delete this->_primitives;
}
