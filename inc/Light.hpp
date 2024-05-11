/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-william.niarquin
** File description:
** Light
*/

#ifndef LIGHT_HPP_
    #define LIGHT_HPP_

    #ifndef _GLIBCXX_OSTREAM
        #include <ostream>
    #endif
    #ifndef VECTOR3D_HPP_
        #include "Vector3D.hpp"
    #endif
    #ifndef COLOR_HPP_
        #include "Color.hpp"
    #endif
    #include "Color.hpp"
    #ifndef RAYSETTING_HPP_
        #include "RaySetting.hpp"
    #endif


/**
 * @brief [Light] class of the light (inherits from RaySetting)
 * This class is used to define the light
 * and to define the methods that the light must have
 * (ex: addition, subtraction, ...)
 * 
 * @param _ambient: the ambient light (0.0 - 1.0)
 * @param _diffuse: the diffuse light (0.0 - 1.0)
 * @param _pointLights: the point light sources (Vector3D)
 * @param _directionalLights: the directional light sources (Vector3D)
 */
class Light : public RaySetting {
    public:
        /**
         * @brief Default construct a new Light object
         */
        Light() = default;

        /**
         * @brief Construct a new Light object
         * 
         * @param ambient light (0.0 - 1.0)
         * @param diffuse light (0.0 - 1.0)
         * @param pointLights sources
         * @param directionalLights sources
         */
        Light(double ambient, double diffuse, const std::vector<Vector3D>& pointLights, const std::vector<Vector3D>& directionalLights) : _ambient(ambient), _diffuse(diffuse), _pointLights(pointLights), _directionalLights(directionalLights) {};

        /**
         * @brief Copy construct a new Light object
         * 
         * @param other
         */
        Light(const Light& other) = default;

        /**
         * @brief Move construct a new Light object
         * 
         * @param other 
         */
        Light(Light&& other) = default;

        /**
         * @brief Destroy the Light object
         * 
         */
        ~Light() = default;



        /**
         * @brief Copy a Light object
         * 
         * @param other 
         * @return Light& 
         */
        Light& operator=(const Light& other) = default;

        /**
         * @brief Move a Light object
         * 
         * @param other 
         * @return Light& 
         */
        Light& operator=(Light&& other) = default;

        /**
         * @brief addition of two lights
         * 
         * @param other 
         * @return Light& 
         */
        Light& operator+=(const Light& other);

        /**
         * @brief subtraction of two lights
         * 
         * @param other 
         * @return Light& 
         */
        Light& operator-=(const Light& other);

        /**
         * @brief addition of two lights
         * 
         * @param other 
         * @return Light 
         */
        Light operator+(const Light& other) const;

        /**
         * @brief subtraction of two lights
         * 
         * @param other 
         * @return Light 
         */
        Light operator-(const Light& other) const;

        /**
         * @brief compare two lights
         * 
         * @param other 
         * @return true|false if the two lights are the same or not
         */
        bool operator==(const Light& other) const;

        /**
         * @brief compare two lights
         * 
         * @param other 
         * @return true|false if the two lights are not the same or not
         */
        bool operator!=(const Light& other) const;



        /**
         * @brief Get the Ambient value
         * 
         * @return double 
         */
        double getAmbient() const;

        /**
         * @brief Get the Diffuse value
         * 
         * @return double 
         */
        double getDiffuse() const;

        /**
         * @brief Get the Point Lights
         * 
         * @return const std::vector<Vector3D>& 
         */
        const std::vector<Vector3D>& getPointLights() const;

        /**
         * @brief Get the Directional Lights
         * 
         * @return const std::vector<Vector3D>& 
         */
        const std::vector<Vector3D>& getDirectionalLights() const;



        /**
         * @brief Set the Ambient value
         * 
         * @param ambient 
         */
        void setAmbient(double ambient);

        /**
         * @brief Set the Diffuse value
         * 
         * @param diffuse 
         */
        void setDiffuse(double diffuse);

        /**
         * @brief Set the Point Lights
         * 
         * @param pointLights 
         */
        void setPointLights(const std::vector<Vector3D>& pointLights);

        /**
         * @brief Set the Directional Lights
         * 
         * @param directionalLights 
         */
        void setDirectionalLights(const std::vector<Vector3D>& directionalLights);



        /**
         * @brief Add new point light source
         * 
         * @param pointLight 
         */
        void addPointLight(const Vector3D& pointLight);

        /**
         * @brief Add new directional light source
         * 
         * @param directionalLight 
         */
        void addDirectionalLight(const Vector3D& directionalLight);



        /**
         * @brief Clear the light
         */
        void clear();

        /**
         * @brief Get the Color of a point with the light settings
         * 
         * @param point of the object
         * @param normal of the object
         * @param color of the object
         * @return Color of the object
         */
        Color getColor(const Vector3D& point, const Vector3D& normal, Color& color) const;

        /**
         * @brief Get the Type object
         * 
         * @return std::string
         */
        std::string getType() override { return "Light"; };

    private:
        double _ambient;
        double _diffuse;
        std::vector<Vector3D> _pointLights;
        std::vector<Vector3D> _directionalLights;
};

#endif /* !LIGHT_HPP_ */
