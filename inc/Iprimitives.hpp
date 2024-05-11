/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-william.niarquin
** File description:
** Iprimitives
*/

#pragma once

#ifndef IPRIMITIVES_HPP_
    #define IPRIMITIVES_HPP_

    #include "Vector3D.hpp"
    #include "Light.hpp"
    #include "raytracer.hpp"
    #include "Ray.hpp"


/**
 * @brief [Iprimitives] Abstract class of primitives (used to define the type of the primitive)
 * ex: Sphere, Plane, Cube, ...
 * This class is used to define the type of the primitive
 * and to define the methods that the primitive must have
 * (ex: intersect, normalize, getNormal, ...)
 */
class Iprimitives {
    public:
        /**
         * @brief Destroy the Iprimitives (virtual because it's an abstract class)
         * 
         */
        virtual ~Iprimitives() = default;



        /**
         * @brief Check if there is an intersection between the ray and the scene
         * 
         * @param ray to check the intersection with the scene
         * @param t the distance between the ray and the intersection point (if there is one)
         * @return true|false if there is an intersection
         */
        virtual bool intersect(const Ray& ray, float& t) const = 0;

        /**
         * @brief Normalize the vector to a length of 1 for the calculations of the intersection point and the normal
         * 
         * @return Vector3D
         */
        virtual Vector3D normalize() const = 0;

        /**
         * @brief Get the Normal of the primitive at the intersection point
         * 
         * @param intersection
         * @return Vector3D 
         */
        virtual Vector3D getNormal(const Vector3D& intersection) const = 0;

        /**
         * @brief Get the Color of the primitive
         * 
         * @return const Color&
         */
        virtual const Color& getColor() const = 0;
};

#endif /* !IPRIMITIVES_HPP_ */
