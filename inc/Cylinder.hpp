/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-william.niarquin
** File description:
** Cylinder
*/

#ifndef CYLINDER_HPP_
    #define CYLINDER_HPP_

    #include "Iprimitives.hpp"
    #include "Vector3D.hpp"
    #include "Color.hpp"


/**
 * @brief [Cylinder] class of the cylinder primitive (inherits from Iprimitives)
 * This class is used to define the cylinder primitive
 * and to define the methods that the cylinder must have
 * (ex: intersect, ...)
 * 
 * @param _position: the position of the cylinder (Vector3D)
 * @param _radius: the radius of the cylinder (float)
 * @param _height: the height of the cylinder (float)
 * @param _color: the color of the cylinder (Color)
 */
class Cylinder : public Iprimitives {
    public:
        /**
         * @brief Defaultc onstruct a new Cylinder object
         * 
         */
        Cylinder() : _position(Vector3D()), _radius(0), _height(0), _color(Color()) {}

        /**
         * @brief Construct a new Cylinder object
         * 
         * @param position of the cylinder (Vector3D)
         * @param direction of the cylinder (Vector3D)
         * @param radius of the cylinder (float)
         * @param height of the cylinder (float)
         * @param color of the cylinder (Color)
         */
        Cylinder(const Vector3D& position, const Vector3D& direction, float radius, float height, Color color);

        /**
         * @brief Copy construct a new Cylinder object
         * 
         * @param other to copy
         */
        Cylinder(const Cylinder& other) = default;

        /**
         * @brief Move construct a new Cylinder object
         * 
         * @param other to move
         */
        Cylinder(Cylinder&& other) = default;

        /**
         * @brief Destroy the Cylinder object
         */
        ~Cylinder() = default;



        /**
         * @brief Copy assignment operator
         * 
         * @param other to copy
         * @return Cylinder
         */
        Cylinder &operator=(const Cylinder &other) = default;

        /**
         * @brief Move assignment operator
         * 
         * @param other to move
         * @return Cylinder
         */
        Cylinder &operator=(Cylinder &&other) = default;



        /**
         * @brief Get the Position value
         * 
         * @return Vector3D 
         */
        Vector3D getPosition() const;

        /**
         * @brief Get the Radius value
         * 
         * @return float 
         */
        float getRadius() const;

        /**
         * @brief Get the Height value
         * 
         * @return float 
         */
        float getHeight() const;

        /**
         * @brief Get the Color value
         * 
         * @return const Color& 
         */
        const Color& getColor() const override;



        /**
         * @brief Set the Position value
         * 
         * @param position 
         */
        void setPosition(const Vector3D& position);

        /**
         * @brief Set the Radius value
         * 
         * @param radius 
         */
        void setRadius(float radius);

        /**
         * @brief Set the Height value
         * 
         * @param height 
         */
        void setHeight(float height);

        /**
         * @brief Set the Color value
         * 
         * @param color 
         */
        void setColor(const Color& color);



        /**
         * @brief method to know if a ray intersects the cylinder
         * 
         * @param ray to test (Ray)
         * @param t the distance between the ray origin and the intersection (float) (if there is one)
         * @return true|false if the ray intersects the cylinder or not (bool)
         */
        bool intersect(const Ray& ray, float& t) const override;

        /**
         * @brief method to get the normal of the cylinder at a given point
         * 
         * @param intersection the point where we want the normal (Vector3D)
         * @return Vector3D the normal of the cylinder at the given point
         */
        Vector3D getNormal(const Vector3D& intersection) const override;

        /**
         * @brief method to normalize the cylinder
         * 
         * @return Vector3D the normalized cylinder
         */
        Vector3D normalize() const override;

    private:
        Vector3D _position;
        Vector3D _direction;
        float _radius;
        float _height;
        Color _color;
};

#endif /* !CYLINDER_HPP_ */
