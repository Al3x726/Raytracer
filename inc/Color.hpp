/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-william.niarquin
** File description:
** Color
*/


#ifndef COLOR_HPP_
    #define COLOR_HPP_

    #include "raytracer.hpp"


/**
 * @brief [Color] class
 * This class is used to represent a color
 * It is composed of 4 unsigned char (r, g, b, a)
 * and a are between 0 and 255
 * it's possible to use the color class with sfml or openGL
 * 
 * @attention: the color is stored in RGBA format
 * 
 * @param r red
 * @param g green
 * @param b blue
 * @param a alpha
 */
class Color {
    public:
        /**
         * @brief Defaultc construct a new Color object
         */
        Color() = default;

        /**
         * @brief Construct a new Color object
         * 
         * @param r 
         * @param g 
         * @param b 
         * @param a 
         */
        Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a = 255) : _r(r), _g(g), _b(b), _a(a) {};

        /**
         * @brief Copy construct a new Color object
         * 
         * @param other 
         */
        Color(const Color& other) = default;

        /**
         * @brief move construct a new Color object
         * 
         * @param other 
         */
        Color(Color&& other) = default;

        /**
         * @brief Destroy the Color object
         * 
         */
        ~Color() = default;



        /**
         * @brief [operator=] copy assignment operator
         * 
         * @param other
         * @return Color
         */
        Color& operator=(const Color& other) = default;

        /**
         * @brief [operator=] move assignment operator
         * 
         * @param other 
         * @return Color
         */
        Color& operator=(Color&& other) = default;

        /**
         * @brief [operator+] add two colors
         * 
         * @param other 
         * @return Color
         */
        Color& operator+(const Color& other);

        /**
         * @brief [operator-] substract two colors
         * 
         * @param other 
         * @return Color
         */
        Color& operator-(const Color& other);

        /**
         * @brief [operator*] multiply two colors
         * 
         * @param other 
         * @return Color
         */
        Color& operator*(const Color& other);

        /**
         * @brief [operator/] divide two colors
         * 
         * @param other 
         * @return Color
         */
        Color& operator/(const Color& other);

        /**
         * @brief [operator+] add a scalar to a color
         * 
         * @param scalar 
         * @return Color
         */
        Color& operator+(const double scalar);

        /**
         * @brief [operator-] substract a scalar to a color
         * 
         * @param scalar 
         * @return Color
         */
        Color& operator-(const double scalar);

        /**
         * @brief [operator*] multiply a scalar to a color
         * 
         * @param scalar 
         * @return Color
         */
        Color& operator*(const double scalar);

        /**
         * @brief [operator/] divide a scalar to a color
         * 
         * @param scalar 
         * @return Color
         */
        Color& operator/(const double scalar);

        /**
         * @brief [operator+=] add two colors
         * 
         * @param other 
         * @return Color
         */
        Color& operator+=(const Color& other);

        /**
         * @brief [operator-=] substract two colors
         * 
         * @param other 
         * @return Color
         */
        Color& operator-=(const Color& other);

        /**
         * @brief [operator*=] multiply two colors
         * 
         * @param other 
         * @return Color
         */
        Color& operator*=(const Color& other);

        /**
         * @brief [operator/=] divide two colors
         * 
         * @param other 
         * @return Color
         */
        Color& operator/=(const Color& other);

        /**
         * @brief [operator+=] add a scalar to a color
         * 
         * @param scalar 
         * @return Color
         */
        Color& operator+=(const double scalar);

        /**
         * @brief [operator-=] substract a scalar to a color
         * 
         * @param scalar
         * @return Color 
         */
        Color& operator-=(const double scalar);

        /**
         * @brief [operator*=] multiply a scalar to a color
         * 
         * @param scalar 
         * @return Color
         */
        Color& operator*=(const double scalar);

        /**
         * @brief [operator/=] divide a scalar to a color
         * 
         * @param scalar 
         * @return Color
         */
        Color& operator/=(const double scalar);

        /**
         * @brief compare two colors
         * 
         * @param other 
         * @return bool: true if the colors are the same, false otherwise
         */
        bool operator==(const Color& other) const;

        /**
         * @brief compare two colors
         * 
         * @param other 
         * @return bool: true if the colors are different, false otherwise
         */
        bool operator!=(const Color& other) const;

        /**
         * @brief print a color
         * 
         * @param os the output stream
         * @return std::ostream
         */
        std::ostream& operator<<(std::ostream& os);



        /**
         * @brief Getter for the red value
         * 
         * @return unsigned char 
         */
        unsigned char getR() const;

        /**
         * @brief Getter for the green value
         * 
         * @return unsigned char 
         */
        unsigned char getG() const;

        /**
         * @brief Getter for the blue value
         * 
         * @return unsigned char 
         */
        unsigned char getB() const;

        /**
         * @brief Getter for the alpha value
         * 
         * @return unsigned char 
         */
        unsigned char getA() const;



        /**
         * @brief Setter for the red value
         * 
         * @param r 
         */
        void setR(unsigned char r);

        /**
         * @brief Setter for the green value
         * 
         * @param g 
         */
        void setG(unsigned char g);

        /**
         * @brief Setter for the blue value
         * 
         * @param b 
         */
        void setB(unsigned char b);

        /**
         * @brief Setter for the alpha value
         * 
         * @param a 
         */
        void setA(unsigned char a);



        /**
         * @brief Apply gamma correction to a color
         * 
         * @param gamma (gamma > 0)
         */
        void gammaCorrection(double gamma);

        /**
         * @brief Mix two colors
         * 
         * @param color1 
         * @param color2 
         * @param factor 
         * @return Color
         */
        static Color mix(const Color& color1, const Color& color2, double factor);

        /**
         * @brief Linear interpolation between two colors
         * 
         * @param color1 
         * @param color2 
         * @param factor 
         * @return Color the interpolated color
         */
        static Color lerp(const Color& color1, const Color& color2, double factor);

        /**
         * @brief blend two colors
         * 
         * @param other 
         * @return the blended Color 
         */
        Color blend(const Color& other);

    private:
        unsigned char _r;
        unsigned char _g;
        unsigned char _b;
        unsigned char _a;
};

#endif /* !COLOR_HPP_ */
