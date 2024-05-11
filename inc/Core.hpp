/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-william.niarquin
** File description:
** Core
*/

#pragma once

#ifndef CORE_HPP_
    #define CORE_HPP_

    #include "raytracer.hpp"
    #include "Config.hpp"
    #include "Camera.hpp"
    #include "Light.hpp"
    #include "ImagePPM.hpp"
    #include "Scene.hpp"


/**
 * @brief [Core] class of the core
 * This class is used to define the core of the raytracer
 * and to define the methods that the core must have
 * (ex: render, ...)
 * 
 * @param _config: the config of the raytracer (Config)
 * @param _camera: the camera of the raytracer (Camera)
 * @param _light: the light of the raytracer (Light)
 * @param _image: the image of the raytracer (ImagePPM)
 * @param _scene: the scene of the raytracer (Scene)
 * @param _primitives: the primitives of the raytracer (std::vector<Iprimitives *>)
 */
class Core {
    public:
        /**
         * @brief Construct a new Core object
         * 
         * @param path the path of the config file
         */
        Core(const char *path);

        /**
         * @brief Destroy the Core object
         */
        ~Core();

    private:        
        Config _config;
        Camera *_camera;
        Light *_light;
        ImagePPM _image;
        Scene _scene;
        std::vector<Iprimitives *> *_primitives;
};

#endif /* !CORE_HPP_ */
