/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-william.niarquin
** File description:
** Scene
*/

#pragma once

#ifndef SCENE_HPP_
    #define SCENE_HPP_

    #include "raytracer.hpp"
    #include "Ray.hpp"
    #include "Camera.hpp"
    #include "Light.hpp"
    #include "Sphere.hpp"
    #include "Plane.hpp"
    #include "Color.hpp"
    #include "Vector3D.hpp"
    #include "Iprimitives.hpp"
    #include "ImagePPM.hpp"



/**
 * @brief [Scene] class of the scene
 * This class is used to define the scene (the camera, the lights and the primitives)
 * and to define the methods that the scene must have
 * (ex: addPrimitive, render, ...)
 * 
 * @param _camera: the camera of the scene
 * @param _light: the light of the scene
 * @param _iprimitives: the primitives of the scene
 */
class Scene {
    public:
        /**
         * @brief Construct a new Scene object
         */
        Scene() = default;

        /**
         * @brief Copy construct a new Scene object
         * 
         * @param scene 
         */
        Scene(const Scene& scene) = default;

        /**
         * @brief Move construct a new Scene object
         * 
         * @param scene 
         */
        Scene(Scene& scene) = default;

        /**
         * @brief Destroy the Scene object
         */
        ~Scene() = default;



        /**
         * @brief Copy assignment operator
         * 
         * @param scene 
         * @return Scene& 
         */
        Scene& operator=(Scene& scene) = default;

        /**
         * @brief Move assignment operator
         * 
         * @param scene 
         * @return Scene& 
         */
        Scene& operator=(const Scene& scene) = default;



        /**
         * @brief Get the Camera object
         * 
         * @return Camera 
         */
        Camera getCamera() const;

        /**
         * @brief Get the Light object
         * 
         * @return Light 
         */
        Light getLight() const;

        /**
         * @brief Get the Iprimitives object
         * 
         * @return std::vector<Iprimitives *> 
         */
        std::vector<Iprimitives *> *getIprimitives() const;



        /**
         * @brief Set the Camera object
         * 
         * @param camera 
         */
        void setCamera(Camera camera);

        /**
         * @brief Set the Light object
         * 
         * @param light 
         */
        void setLight(Light light);

        /**
         * @brief Set the Iprimitives object
         * 
         * @param iprimitives 
         */
        void setIprimitives(std::vector<Iprimitives *> *iprimitives);

        /**
         * @brief Add new primitive to the scene
         * 
         * @param primitive 
         */
        void addPrimitive(Iprimitives *primitive);



        /**
         * @brief Method for all primitives in the scene
         * 
         * @param ray to intersect with the scene
         * @param intersection point if there is one
         * @return true|false if there is an intersection or not
         */
        bool intersect(const Ray& ray, Vector3D& intersection) const;

        /**
         * @brief Method for all primitives in the scene
         * 
         * @param ray to intersect with the scene
         * @param intersection point if there is one
         * @param normal of the primitive at the intersection point if there is one
         * @param color of the primitive at the intersection point if there is one
         * @return true|false if there is an intersection or not
         */
        bool intersect(const Ray& ray, Vector3D& intersection, Vector3D &noraml, Color& color) const;

        /**
         * @brief trace method for all primitives in the scene
         * 
         * @param ray to trace with the scene (from the camera)
         * @param depth of the ray (for reflection)
         * @return Color at this pixel (the color of the primitive)
         */
        Color trace(const Ray& ray, int depth) const;

        /**
         * @brief Render the scene
         * 
         * @param image to render (the image will be modified in this method)
         */
        void render(ImagePPM& image) const;

        /**
         * @brief Put the rendering of the scene
         * 
         * @param x coordinate of the pixel
         * @param y coordinate of the pixel
         * @param width the pixel
         * @param height of the pixel
         */
        void putRendering(int x, int y, int width, int height) const;

    private:
        Camera _camera;
        Light _light;
        std::vector<Iprimitives *> *_primitives;
        int _maxDepth = 5;
};

#endif /* !SCENE_HPP_ */
