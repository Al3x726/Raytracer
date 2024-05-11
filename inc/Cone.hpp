/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-william.niarquin
** File description:
** Cone
*/

#ifndef CONE_HPP_
    #define CONE_HPP_

    #include "Vector3D.hpp"
    #include "Iprimitives.hpp"


/**
 * @brief [Cone] class of the cone primitive (inherits from Iprimitives)
 * This class is used to define the cone primitive
 * and to define the methods that the cone must have
 * (ex: intersect, ...)
 * 
 * @param _position: the position of the cone (Vector3D)
 * @param _direction: the direction of the cone (Vector3D)
 * @param _radius: the radius of the cone (float)
 * @param _height: the height of the cone (float)
 * @param _color: the color of the cone (Color)
 */
class Cone : public Iprimitives {
    public:
        /**
         * @brief default construct a new Cone object
         * 
         */
        Cone() : _position(Vector3D()), _direction(Vector3D()), _radius(0), _height(0), _color(Color()) {}

        /**
         * @brief Construct a new Cone object
         * 
         * @param position 
         * @param direction 
         * @param radius 
         * @param height 
         * @param color 
         */
        Cone(const Vector3D& position, const Vector3D& direction, float radius, float height, Color color);

        /**
         * @brief Copy construct a new Cone object
         * 
         * @param other 
         */
        Cone(const Cone& other) = default;

        /**
         * @brief Move construct a new Cone object
         * 
         * @param other 
         */
        Cone(Cone&& other) = default;

        /**
         * @brief Destroy the Cone object
         * 
         */
        ~Cone() = default;



        /**
         * @brief Copy assignment operator
         * 
         * @param other the cone to copy
         * @return Cone
         */
        Cone &operator=(const Cone &other) = default;

        /**
         * @brief Move assignment operator
         * 
         * @param other the cone to move
         * @return Cone
         */
        Cone &operator=(Cone &&other) = default;



        /**
         * @brief Get the Position object
         * 
         * @return Vector3D 
         */
        Vector3D getPosition() const;

        /**
         * @brief Get the Direction object
         * 
         * @return Vector3D 
         */
        Vector3D getDirection() const;

        /**
         * @brief Get the Radius object
         * 
         * @return float (radius)
         */
        float getRadius() const;

        /**
         * @brief Get the Height object
         * 
         * @return float 
         */
        float getHeight() const;



        /**
         * @brief Set the Position object
         * 
         * @param position
         */
        void setPosition(const Vector3D& position);

        /**
         * @brief Set the Direction object
         * 
         * @param direction 
         */
        void setDirection(const Vector3D& direction);

        /**
         * @brief Set the Radius object
         * 
         * @param radius 
         */
        void setRadius(float radius);

        /**
         * @brief Set the Height object
         * 
         * @param height 
         */
        void setHeight(float height);



        /**
         * @brief method to know if a ray intersect the cone
         * 
         * @param ray to test
         * @param t the distance between the ray origin and the intersection (if there is an intersection)
         * @return true|false if the ray intersect the cone 
         */
        bool intersect(const Ray& ray, float& t) const override;

        /**
         * @brief method to normalize the cone
         * 
         * @return Vector3D 
         */
        Vector3D normalize() const override;

        /**
         * @brief Get the Normal object
         * 
         * @param intersection 
         * @return Vector3D 
         */
        Vector3D getNormal(const Vector3D& intersection) const override;

        /**
         * @brief Get the Color object
         * 
         * @return const Color
         */
        const Color& getColor() const override;

    private:
        Vector3D _position;
        Vector3D _direction;
        float _radius;
        float _height;
        Color _color;
};

#endif /* !CONE_HPP_ */
