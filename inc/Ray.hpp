/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-william.niarquin
** File description:
** Ray
*/

#pragma once

#ifndef RAY_HPP_
    #define RAY_HPP_

    #include "raytracer.hpp"
    #include "Vector3D.hpp"



// [Ray] Class of Ray (used to define a ray)
// A ray is defined by an origin and a direction (ex: (0, 0, 0) and (1, 0, 0))
// The ray is used to check if there is an intersection between the ray and the scene
// (ex: if there is an intersection between the ray and a sphere)
// The ray is also used to check if there is an intersection between the ray and the light
// (ex: if there is an intersection between the ray and the light, the point is in the shadow)
// The ray is also used to check if there is an intersection between the ray and the camera
// (ex: if there is an intersection between the ray and the camera, the point is visible)
// The ray is also used to check if there is an intersection between the ray and all the objects in the scene
// (ex: if there is an intersection between the ray and a sphere, the point is visible)
// \param _origin: the origin of the ray (ex: (0, 0, 0)) (Vector3D)
// \param _direction: the direction of the ray (ex: (1, 0, 0)) (Vector3D) (must be normalized)
/**
 * @brief [Ray] Class of Ray (used to define a ray)
 * A ray is defined by an origin and a direction (ex: (0, 0, 0) and (1, 0, 0))
 * The ray is used to check if there is an intersection between the ray and the scene
 * (ex: if there is an intersection between the ray and a sphere)
 * The ray is also used to check if there is an intersection between the ray and the light
 * (ex: if there is an intersection between the ray and the light, the point is in the shadow)
 * The ray is also used to check if there is an intersection between the ray and the camera
 * (ex: if there is an intersection between the ray and the camera, the point is visible)
 * The ray is also used to check if there is an intersection between the ray and all the objects in the scene
 * (ex: if there is an intersection between the ray and a sphere, the point is visible)
 * 
 * \param _origin: the origin of the ray (ex: (0, 0, 0)) (Vector3D)
 * \param _direction: the direction of the ray (ex: (1, 0, 0)) (Vector3D) (must be normalized)
 */
class Ray {
    public:

        /**
         * @brief Default constructor of Ray (create a ray with origin (0, 0, 0) and direction (0, 0, 0) (null vector))
         * 
         */
        Ray();

        /**
         * @brief Construct a new Ray object
         * 
         * @param origin of the ray
         * @param direction of the ray
         */
        Ray(const Vector3D& origin, const Vector3D& direction);

        /**
         * @brief Copy constructor of Ray
         * 
         * @param other 
         */
        Ray(const Ray& other) = default;

        /**
         * @brief Move constructor of Ray
         * 
         * @param other 
         */
        Ray(Ray&& other);

        /**
         * @brief Destroy the Ray object
         */
        ~Ray() = default;



        /**
         * @brief Move operator of Ray
         * 
         * @param other 
         * @return Ray& 
         */
        Ray& operator=(const Ray& other) = default;

        /**
         * @brief Move operator of Ray
         * 
         * @param other 
         * @return Ray& 
         */
        Ray& operator=(Ray&& other);



        /**
         * @brief Get the Origin value
         * 
         * @return const Vector3D& 
         */
        const Vector3D& getOrigin() const;

        /**
         * @brief Get the Direction value
         * 
         * @return const Vector3D& 
         */
        const Vector3D& getDirection() const;

        


        /**
         * @brief Set the Origin value
         * 
         * @param origin 
         */
        void setOrigin(const Vector3D& origin);
        
        /**
         * @brief Set the Direction value
         * 
         * @param direction 
         */
        void setDirection(const Vector3D& direction);

    private:
        Vector3D _origin;
        Vector3D _direction;
};

#endif /* !RAY_HPP_ */
