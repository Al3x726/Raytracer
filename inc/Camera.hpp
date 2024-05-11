/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-william.niarquin
** File description:
** Camera
*/

#ifndef CAMERA_HPP_
    #define CAMERA_HPP_


    #ifndef RAYSETTING_HPP_
        #include "RaySetting.hpp"
    #endif
    #ifndef COLOR_HPP_
        #include "Color.hpp"
    #endif
    #ifndef VECTOR3D_HPP_
        #include "Vector3D.hpp"
    #endif
    #ifndef RAY_HPP_
        #include "Ray.hpp"
    #endif
    #ifndef SFML_GRAPHICS_HPP_
        #include <SFML/Graphics.hpp>
    #endif

/**
 * @brief [Camera] The camera is the point of view of the scene
 * It contains the position, the rotation, the field of view and the resolution
 * It also contains the pixels of the camera
 * It inherits from RaySetting
 * 
 * @param _position: position of the camera (x, y, z)
 * @param _rotation: rotation of the camera (in degrees: x, y, z)
 * @param _fov: field of view of the camera (in degrees)
 * @param _resolution: resolution of the camera (width, height)
 */
class Camera : public RaySetting {
    public:
        /**
         * @brief Default construct a new Camera object
         * 
         */
        Camera() : _position(Vector3D()), _rotation(Vector3D()), _fov(0.0), _resolution(0,0) {};

        /**
         * @brief Construct a new Camera object
         * 
         * @param position position of the camera (x, y, z)
         * @param rotation rotation of the camera (in degrees: x, y, z)
         * @param fov field of view of the camera (in degrees)
         * @param resolution resolution of the camera (width, height)
         */
        Camera(Vector3D position, Vector3D rotation, double fov, sf::Vector2i resolution);

        /**
         * @brief Copy constructor of Camera
         * 
         * @param Camera 
         */
        Camera(const Camera& camera) = default;

        /**
         * @brief Move constructor of Camera
         * 
         * @param Camera 
         */
        Camera(Camera& camera) = default;

        /**
         * @brief Destroy the Camera object
         * 
         */
        ~Camera() = default;



        /**
         * @brief Operator = of Camera (copy the Camera)
         * 
         * @param Camera The Camera to copy
         * @return Camera& 
         */
        Camera& operator=(Camera& camera) = default;

        /**
         * @brief Move operator of Camera (move the Camera)
         * 
         * @param Camera The Camera to move
         * @return Camera& 
         */
        Camera& operator=(const Camera& camera) = default;



        /**
         * @brief Get the position of the camera
         * 
         * @return Vector3D 
         */
        Vector3D getPosition() const;

        /**
         * @brief Get the rotation of the camera
         * 
         * @return Vector3D (in degrees)
         */
        Vector3D getRotation() const;

        /**
         * @brief Get the Fov of the camera (in degrees)
         * 
         * @return double 
         */
        double getFov() const;

        /**
         * @brief Get the Resolution of the camera
         * 
         * @return sf::Vector2i (width = x, height = y)
         */
        sf::Vector2i getResolution() const;

        /**
         * @brief Get the Pixels of the camera (width * height) (r, g, b)
         * 
         * @return std::vector<Color> 
         */
        std::vector<Color> getPixels() const;

        /**
         * @brief Get the Pixel of the camera
         * 
         * @param x coordinate of the pixel on the screen (width)
         * @param y coordinate of the pixel on the screen (height)
         * @return Color
         */
        Color getPixel(int x, int y) const;

        /**
         * @brief Get the Pixel of the camera
         * 
         * @param index of the pixel on the screen (width * y + x)
         * @return Color 
         */
        Color getPixel(int index) const;



        /**
         * @brief Set the Position of the camera
         * 
         * @param position 
         */
        void setPosition(Vector3D position);

        /**
         * @brief Set the Rotation of the camera
         * 
         * @param rotation 
         */
        void setRotation(Vector3D rotation);

        /**
         * @brief Set the Fov of the camera
         * 
         * @param fov (in degrees)
         */
        void setFov(double fov);

        /**
         * @brief Set the Resolution of the camera
         * 
         * @param resolution (width, height)
         */
        void setResolution(sf::Vector2i resolution);

        /**
         * @brief Set the Pixels of the camera
         * 
         * @param pixels 
         */
        void setPixels(std::vector<Color> pixels);

        /**
         * @brief Set the Pixel of the camera at the index
         * 
         * @param x (wigth)
         * @param y (height)
         * @param color of the pixel
         */
        void setPixel(int x, int y, Color color);

        /**
         * @brief Set the Pixel of the camera at the index
         * 
         * @param index of the pixel in the vector
         * @param color of the pixel
         */
        void setPixel(int index, Color color);



        /**
         * @brief Get the Ray from the camera to the pixel (x, y) on the screen
         * 
         * @param x coordinate of the pixel on the screen (width)
         * @param y coordinate of the pixel on the screen (height)
         * @return Ray 
         */
        Ray getRay(float x, float y) const;

        /**
         * @brief Get the Type of the object
         * 
         * @return "Camera"
         */
        std::string getType() override { return "Camera"; }

    private:
        Vector3D _position;
        Vector3D _rotation;
        Vector3D _up;
        Vector3D _right;
        double _fov;
        sf::Vector2i _resolution;
        std::vector<Color> _pixels;
};

#endif /* !CAMERA_HPP_ */
