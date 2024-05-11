/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-william.niarquin
** File description:
** Plane
*/

#pragma once

#ifndef PLANE_HPP_
    #define PLANE_HPP_

    #include "Iprimitives.hpp"
    #include "Vector3D.hpp"
    #include "Color.hpp"
    #include "Light.hpp"
    #include "Ray.hpp"
    #include "raytracer.hpp"


/**
 * @brief [Plane] class of the plane primitive (inherits from Iprimitives)
 * This class is used to define the plane primitive
 * and to define the methods that the plane must have
 * (ex: intersect, ...)
 * 
 * @param _axis: the axis of the plane (0 = x, 1 = y, 2 = z)
 * @param _position: the position of the plane on the axis (double)
 * @param _color: the color of the plane (Color)
 */
class Plane  : public Iprimitives {
    public:
        /**
         * @brief Default construct a new Plane object
         */
        Plane() = default;

        /**
         * @brief Construct a new Plane object
         * 
         * @param axis of the plane (0 = x, 1 = y, 2 = z)
         * @param position of the plane on the axis
         * @param color of the plane
         */
        Plane(const int& axis, const double& position, const Color& color);

        /**
         * @brief Copy construct a new Plane object
         * 
         * @param other 
         */
        Plane(const Plane& other) = default;

        /**
         * @brief Move construct a new Plane object
         * 
         * @param other 
         */
        Plane(Plane&& other) = default;

        /**
         * @brief Destroy the Plane object
         * 
         */
        ~Plane() = default;



        /**
         * @brief Copy assignment operator
         * 
         * @param other 
         * @return Plane& 
         */
        Plane& operator=(const Plane& other) = default;

        /**
         * @brief Move assignment operator
         * 
         * @param other 
         * @return Plane& 
         */
        Plane& operator=(Plane&& other) = default;



        /**
         * @brief Get the Axis value
         * 
         * @return int 
         */
        int getAxis() const;

        /**
         * @brief Get the Position value
         * 
         * @return double 
         */
        double getPosition() const;

        /**
         * @brief Get the Color value
         * 
         * @return const Color& 
         */
        const Color& getColor() const override;



        /**
         * @brief Set the Axis value
         * 
         * @param axis 
         */
        void setAxis(const int& axis);

        /**
         * @brief Set the Position value
         * 
         * @param position 
         */
        void setPosition(const double& position);

        /**
         * @brief Set the Color value
         * 
         * @param color 
         */
        void setColor(const Color& color);



        /**
         * @brief method to check if a ray intersect with the plane
         * 
         * @param ray to hnow if it intersect with the plane
         * @param t the intersection point if there is one
         * @return true|false if there is an intersection or not
         */
        bool intersect(const Ray& ray, float& t) const override;

        /**
         * @brief method to get the normal of the plane
         * 
         * @return Vector3D
         */
        Vector3D normalize() const override;

        /**
         * @brief Get the Normal object at a given point
         * 
         * @param point to get the normal from
         * @return Vector3D 
         */
        Vector3D getNormal(const Vector3D& point) const override;

    private:
        double _a, _b, _c, _d;
        int _axis;
        double _position;
        Color _color;
};

#endif /* !PLANE_HPP_ */
