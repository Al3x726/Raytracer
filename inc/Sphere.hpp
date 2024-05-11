/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-william.niarquin
** File description:
** Sphere
*/

#pragma once

#ifndef SPHERE_HPP_
    #define SPHERE_HPP_

    #include "raytracer.hpp"
    #include "Vector3D.hpp"
    #include "Vector3D.hpp"
    #include "Iprimitives.hpp"
    #include "Color.hpp"


/**
 * @brief [Sphere] class of the sphere primitive (inherits from Iprimitives)
 * This class is used to define the sphere primitive
 * and to define the methods that the sphere must have
 * (ex: intersect, ...)
 * 
 * @param _center: the center of the sphere (Vector3D)
 * @param _radius: the radius of the sphere (double)
 * @param _color: the color of the sphere (Color)
 */
class Sphere : public Iprimitives {
    public:
        /**
         * @brief Default construct a new Sphere object
         */
        Sphere() : _center(Vector3D()), _radius(0), _color(Color()) {};

        /**
         * @brief Construct a new Sphere object
         * 
         * @param center 
         * @param radius 
         * @param color 
         */
        Sphere(const Vector3D& center, const double& radius, Color color) : _center(center), _radius(radius), _color(color) {};

        /**
         * @brief Copy construt a new Sphere object
         * 
         * @param other 
         */
        Sphere(const Sphere& other) = default;

        /**
         * @brief Move construct a new Sphere object
         * 
         * @param other 
         */
        Sphere(Sphere&& other) = default;

        /**
         * @brief Destroy the Sphere object
         */
        ~Sphere() = default;



        /** 
         * @brief Copy assignment operator
         * 
         * @param other 
         * @return Sphere& 
         */
        Sphere& operator=(const Sphere& other) = default;

        /** 
         * @brief Move assignment operator
         * 
         * @param other 
         * @return Sphere& 
         */
        Sphere& operator=(Sphere&& other) = default;



        /**
         * @brief Get the Center of the sphere
         * 
         * @return const Vector3D& 
         */
        const Vector3D& getCenter() const;

        /** 
         * @brief Get the Radius of the sphere
         * 
         * @return const double& 
         */
        const double& getRadius() const;



        /**
         * @brief Set the Center of the sphere
         * 
         * @param center 
         */
        void setCenter(const Vector3D& center);

        /**
         * @brief Set the Radius of the sphere
         * 
         * @param radius 
         */
        void setRadius(const double& radius);

        /**
         * @brief Get the Color of the sphere
         * 
         * @return const Color& 
         */
        const Color& getColor() const override { return _color; }



        /**
         * @brief method to intersect a ray with a sphere (if there is an intersection) and to get the intersection point
         * 
         * @param ray to intersect with the scene
         * @param intersection point if there is one
         * @return true|false if there is an intersection or not 
         */
        bool intersect(const Ray& ray, float& t) const override {
            float a = ray.getDirection().dot(ray.getDirection());
            float b = 2 * (ray.getDirection().getX()*(ray.getOrigin().getX() - _center.getX()) + ray.getDirection().getY()*(ray.getOrigin().getY() - _center.getY()) + ray.getDirection().getZ()*(ray.getOrigin().getZ() - _center.getZ()));
            float c = pow(ray.getOrigin().getX() - _center.getX(), 2) + pow(ray.getOrigin().getY() - _center.getY(), 2) + pow(ray.getOrigin().getZ() - _center.getZ(), 2) - pow(_radius, 2);

            float delta = pow(b, 2) - 4 * a * c;

            if (delta < 0) return false;

            float t1 = (-b + sqrt(delta)) / (2 * a);
            float t2 = (-b - sqrt(delta)) / (2 * a);

            if (t1 < 0 && t2 < 0) return false;
            if (t1 < 0) t = t2;
            else if (t2 < 0) t = t1;
            else t = std::min(t1, t2);
            return true;
        }

        /**
         * @brief method to normalize the sphere
         * 
         * @return Vector3D 
         */
        Vector3D normalize() const override {
            return _center.normalize();
        }

        /**
         * @brief method to get the normal of the sphere at a given point
         * 
         * @param point 
         * @return Vector3D 
         */
        Vector3D getNormal(const Vector3D& point) const override {
            return (point - _center).normalize();
        }

    private:
        Vector3D _center;
        double _radius;
        Color _color;
};

#endif /* !SPHERE_HPP_ */
