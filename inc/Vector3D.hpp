/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-william.niarquin
** File description:
** Vector3D
*/


#ifndef VECTOR3D_HPP_
    #define VECTOR3D_HPP_

    #ifndef _GLIBCXX_CMATH
        #include <cmath>
    #endif
    #ifndef _GLIBCXX_VECTOR
        #include <vector>
    #endif
    #ifndef _GLIBCXX_OSTREAM
        #include <ostream>
    #endif


/**
 * @brief [Vector3D] class of the vector3D
 * This class is used to define the vector3D
 * and to define the methods that the vector3D must have
 * (ex: addition, subtraction, ...)
 * 
 * @param _x: the x coordinate
 * @param _y: the y coordinate
 * @param _z: the z coordinate
 */
class Vector3D {
    public:
        /**
         * @brief Construct a new Vector3D object
         * 
         * @param x coordinate
         * @param y coordinate
         * @param z coordinate
         */
        Vector3D(double x = 0, double y = 0, double z = 0) : _x(x), _y(y), _z(z) {}
        /**
         * @brief Construct a new Vector3D object
         * 
         * @param other
         */
        Vector3D(const Vector3D& other) = default;
        /**
         * @brief Construct a new Vector3D object
         * 
         * @param other
         */
        Vector3D(Vector3D&& other) = default;

        /**
         * @brief Destroy the Vector3D object
         */
        ~Vector3D() = default;



        /**
         * @brief Copy assignment operator
         * 
         * @param other
         * @return Vector3D&
         */
        Vector3D& operator=(const Vector3D& other) = default;

        /**
         * @brief Move assignment operator
         * 
         * @param other
         * @return Vector3D&
         */
        Vector3D& operator=(Vector3D&& other) = default;

        /**
         * @brief Add two vectors
         * 
         * @param other
         * @return Vector3D
         */
        Vector3D operator+(const Vector3D& other) const;

        /**
         * @brief Substract two vectors
         * 
         * @param other
         * @return Vector3D
         */
        Vector3D operator-(const Vector3D& other) const;

        /**
         * @brief Multiply two vectors
         * 
         * @param other
         * @return Vector3D
         */
        Vector3D operator*(const Vector3D& other) const;

        /**
         * @brief Divide two vectors
         * 
         * @param other
         * @return Vector3D
         */
        Vector3D operator/(const Vector3D& other) const;

        /**
         * @brief Add two vectors
         * 
         * @param other
         * @return Vector3D&
         */
        Vector3D& operator+=(const Vector3D& other);

        /**
         * @brief Substract two vectors
         * 
         * @param other
         * @return Vector3D&
         */
        Vector3D& operator-=(const Vector3D& other);
        /**
         * @brief Multiply two vectors
         * 
         * @param other
         * @return Vector3D&
         */
        Vector3D& operator*=(const Vector3D& other);
        
        /**
         * @brief Divide two vectors
         * 
         * @param other
         * @return Vector3D&
         */
        Vector3D& operator/=(const Vector3D& other);

        /**
         * @brief Add a scalar to a vector
         * 
         * @param scalar
         * @return Vector3D
         */
        Vector3D operator+(double scalar) const;

        /**
         * @brief Substract a scalar to a vector
         * 
         * @param scalar
         * @return Vector3D
         */
        Vector3D operator-(double scalar) const;

        /**
         * @brief Multiply a scalar to a vector
         * 
         * @param scalar
         * @return Vector3D
         */
        Vector3D operator*(double scalar) const;

        /**
         * @brief Divide a scalar to a vector
         * 
         * @param scalar
         * @return Vector3D
         */
        Vector3D operator/(double scalar) const;

        /**
         * @brief Add a scalar to a vector
         * 
         * @param scalar
         * @return Vector3D&
         */
        Vector3D& operator+=(double scalar);

        /**
         * @brief Substract a scalar to a vector
         * 
         * @param scalar
         * @return Vector3D&
         */
        Vector3D& operator-=(double scalar);

        /**
         * @brief Multiply a scalar to a vector
         * 
         * @param scalar
         * @return Vector3D&
         */
        Vector3D& operator*=(double scalar);

        /**
         * @brief Divide a scalar to a vector
         * 
         * @param scalar
         * @return Vector3D&
         */
        Vector3D& operator/=(double scalar);

        /**
         * @brief Negate a vector
         * 
         * @return Vector3D 
         */
        Vector3D operator-() const;

        /**
         * @brief Compare two vectors
         * 
         * @param other 
         * @return true|false if the two vectors are equal or not
         */
        bool operator==(const Vector3D& other) const;

        /**
         * @brief Compare two vectors
         * 
         * @param other 
         * @return true|false if the two vectors are different or not
         */
        bool operator!=(const Vector3D& other) const;

        /**
         * @brief Compare two vectors
         * 
         * @param other 
         * @return true|false if the first vector is smaller than the second or not
         */
        bool operator<(const Vector3D& other) const;

        /**
         * @brief Compare two vectors
         * 
         * @param other 
         * @return true|false if the first vector is smaller or equal than the second or not
         */
        bool operator<=(const Vector3D& other) const;

        /**
         * @brief Compare two vectors
         * 
         * @param other 
         * @return true|false if the first vector is greater than the second or not
         */
        bool operator>(const Vector3D& other) const;

        /**
         * @brief Compare two vectors
         * 
         * @param other 
         * @return true|false if the first vector is greater or equal than the second or not
         */
        bool operator>=(const Vector3D& other) const;


        /**
         * @brief Overload for std::ostream
         * 
         * @param os is the stream to write in
         * @return std::ostream&
         */
        std::ostream &operator<<(std::ostream &os) const;



        /**
         * @brief Get the Vector object
         * 
         * @return std::vector<double> 
         */
        std::vector<double> getVector() const;

        /**
         * @brief Get the X object
         * 
         * @return double 
         */
        double getX() const;

        /**
         * @brief Get the Y object
         * 
         * @return double 
         */
        double getY() const;

        /**
         * @brief Get the Z object
         * 
         * @return double 
         */
        double getZ() const;




        /**
         * @brief Set the Vector object
         * 
         * @param x 
         * @param y 
         * @param z 
         */
        void setVector(double x, double y, double z);

        /**
         * @brief Set X in the vector
         * 
         * @param x 
         */
        void setX(double x);

        /**
         * @brief Set Y in the vector
         * 
         * @param y 
         */
        void setY(double y);

        /**
         * @brief Set Z in the vector
         * 
         * @param z 
         */
        void setZ(double z);



        /**
         * @brief translate the vector with another vector
         * 
         * @param v 
         */
        void translate(const Vector3D& v);

        /**
         * @brief rotate the vector on the x axis
         * 
         * @param angle 
         */
        void rotateX(double angle);

        /**
         * @brief rotate the vector on the y axis
         * 
         * @param angle 
         */
        void rotateY(double angle);

        /**
         * @brief rotate the vector on the z axis
         * 
         * @param angle 
         */
        void rotateZ(double angle);

        /**
         * @brief normalize the vector
         * 
         * @return Vector3D 
         */
        Vector3D normalize() const;

        /**
         * @brief calculate the cross product of two vectors
         * 
         * @param v 
         * @return Vector3D 
         */
        Vector3D cross(const Vector3D& v) const;

        /**
         * @brief calculate the dot product of two vectors
         * 
         * @param other 
         * @return float
         */
        float dot(const Vector3D& other) const;

        /**
         * @brief calculate the length of the vector
         * 
         * @return double
         */
        double length() const;

        /**
         * @brief calculate the squared length of the vector (faster than length)
         * 
         * @return Vector3D 
         */
        Vector3D squaredLength() const;

        /**
         * @brief calculate the reflection vector of this vector
         * 
         * @param normal 
         * @return Vector3D 
         */
        Vector3D reflect(const Vector3D& normal) const;

        /**
         * @brief calculate the magnitude vector of this vector
         * 
         * @return Vector3D 
         */
        Vector3D magnitude() const;

        /**
         * @brief linear interpolation between two vectors
         * 
         * @param v other vector to interpolate with this one
         * @param t interpolation value between 0.0f and 1.0f
         * @return Vector3D 
         */
        Vector3D lerp(const Vector3D& v, float t) const;

        /**
         * @brief calculate the distance between two vectors
         * 
         * @param v 
         * @return float 
         */
        float distance(const Vector3D& v) const;

        /**
         * @brief calculate the angle between two vectors
         * 
         * @param v 
         * @return float 
         */
        float angle(const Vector3D& v) const;

        /**
         * @brief return the minimum values between two vectors
         * 
         * @param v 
         * @return Vector3D 
         */
        Vector3D min(const Vector3D& v) const;

        /**
         * @brief return the maximum values between two vectors
         * 
         * @param v 
         * @return Vector3D 
         */
        Vector3D max(const Vector3D& v) const;

        /**
         * @brief clamp the values of the vector between min and max
         * 
         * @param min 
         * @param max 
         * @return Vector3D 
         */
        Vector3D clamp(const Vector3D& min, const Vector3D& max);

        /**
         * @brief calculate the sum of the vector
         * 
         * @return float 
         */
        float somme() const;

        /**
         * @brief calculate the substraction of the vector
         * 
         * @return float 
         */
        float substract() const;

        /**
         * @brief calculate the product of the vector
         * 
         * @return float 
         */
        float produit() const;

        /**
         * @brief calculate the division of the vector
         * 
         * @return float 
         */
        float division() const;

    private:
        double _x;
        double _y;
        double _z;
};

#endif /* !VECTOR3D_HPP_ */
