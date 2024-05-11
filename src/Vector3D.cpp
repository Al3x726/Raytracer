/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-william.niarquin
** File description:
** Vector3D
*/

#include "Vector3D.hpp"

// Getters

std::vector<double> Vector3D::getVector() const
{ return std::vector<double>{_x, _y, _z}; }

double Vector3D::getX() const { return _x; }

double Vector3D::getY() const { return _y; }

double Vector3D::getZ() const{ return _z; }


// Setters

void Vector3D::setX(double x) { _x = x; }
void Vector3D::setY(double y) { _y = y; }
void Vector3D::setZ(double z) { _z = z; }
void Vector3D::setVector(double x, double y, double z)
{
    _x = x;
    _y = y;
    _z = z;
}

// Operators

Vector3D Vector3D::operator+(const Vector3D &other) const
{ return Vector3D(_x + other._x, _y + other._y, _z + other._z); }

Vector3D Vector3D::operator-(const Vector3D &other) const
{ return Vector3D(_x - other._x, _y - other._y, _z - other._z); }

Vector3D Vector3D::operator*(const Vector3D &other) const
{ return Vector3D(_x * other._x, _y * other._y, _z * other._z); }

Vector3D Vector3D::operator/(const Vector3D &other) const
{ return Vector3D(_x / other._x, _y / other._y, _z / other._z); }

Vector3D &Vector3D::operator+=(const Vector3D &other)
{ return *this = *this + other; }

Vector3D &Vector3D::operator-=(const Vector3D &other)
{ return *this = *this - other; }

Vector3D &Vector3D::operator*=(const Vector3D &other)
{ return *this = *this * other; }

Vector3D &Vector3D::operator/=(const Vector3D &other)
{ return *this = *this / other; }

Vector3D Vector3D::operator+(double scalar) const
{ return Vector3D(_x + scalar, _y + scalar, _z + scalar); }

Vector3D Vector3D::operator-(double scalar) const
{ return Vector3D(_x - scalar, _y - scalar, _z - scalar); }

Vector3D Vector3D::operator*(double scalar) const
{ return Vector3D(_x * scalar, _y * scalar, _z * scalar); }

Vector3D Vector3D::operator/(double scalar) const
{ return Vector3D(_x / scalar, _y / scalar, _z / scalar); }

Vector3D &Vector3D::operator+=(double scalar)
{ return *this = *this + scalar; }

Vector3D &Vector3D::operator-=(double scalar)
{ return *this = *this - scalar; }

Vector3D &Vector3D::operator*=(double scalar)
{ return *this = *this * scalar;}

Vector3D &Vector3D::operator/=(double scalar)
{ return *this = *this / scalar; }

Vector3D Vector3D::operator-() const
{ return Vector3D(-_x, -_y, -_z); }

bool Vector3D::operator==(const Vector3D &other) const
{ return _x == other._x && _y == other._y && _z == other._z; }

bool Vector3D::operator!=(const Vector3D &other) const
{ return !(*this == other); }

bool Vector3D::operator<(const Vector3D &other) const
{ return _x < other._x && _y < other._y && _z < other._z; }

bool Vector3D::operator>(const Vector3D &other) const
{ return _x > other._x && _y > other._y && _z > other._z; }

bool Vector3D::operator<=(const Vector3D &other) const
{ return _x <= other._x && _y <= other._y && _z <= other._z; }

bool Vector3D::operator>=(const Vector3D &other) const
{ return _x >= other._x && _y >= other._y && _z >= other._z; }

std::ostream &Vector3D::operator<<(std::ostream &os) const
{
    os << "Vector3D(" << _x << ", " << _y << ", " << _z << ")";
    return os;
}




// Methods

void Vector3D::translate(const Vector3D &v)
{
    _x += v._x;
    _y += v._y;
    _z += v._z;
}

void Vector3D::rotateX(double angle)
{
    double rad = angle * M_PI / 180;
    double cosAngle = std::cos(rad);
    double sinAngle = std::sin(rad);

    this->_x = sinAngle * _y + cosAngle * _z;
    this->_y = cosAngle * _y - sinAngle * _z;
}

void Vector3D::rotateY(double angle)
{
    double rad = angle * M_PI / 180;
    double cosAngle = std::cos(rad);
    double sinAngle = std::sin(rad);

    this->_x = cosAngle * _x + sinAngle * _z;
    this->_z = -sinAngle * _x - cosAngle * _z;
}

void Vector3D::rotateZ(double angle)
{
    double rad = angle * M_PI / 180;
    double cosAngle = std::cos(rad);
    double sinAngle = std::sin(rad);

    this->_x = cosAngle * _x - sinAngle * _y;
    this->_y = sinAngle * _x + cosAngle * _y;
}

float Vector3D::dot(const Vector3D &other) const
{ return _x * other._x + _y * other._y + _z * other._z; }

double Vector3D::length() const
{ return std::sqrt(_x * _x + _y * _y + _z * _z); }

Vector3D Vector3D::normalize() const
{
    double length = this->length();

    if (length == 0) return Vector3D(0, 0, 0);
    return Vector3D(_x / length, _y / length, _z / length);
}

Vector3D Vector3D::cross(const Vector3D &other) const
{
    double x = _y * other._z - _z * other._y;
    double y = _z * other._x - _x * other._z;
    double z = _x * other._y - _y * other._x;

    return Vector3D(x, y, z);
}

Vector3D Vector3D::squaredLength() const
{ return Vector3D(_x * _x, _y * _y, _z * _z); }

Vector3D Vector3D::reflect(const Vector3D &normal) const
{
    Vector3D n = normal.normalize();
    Vector3D v = this->normalize();

    return v - n * 2 * v.dot(n);
}

Vector3D Vector3D::magnitude() const
{ return Vector3D(sqrt(pow(_x, 2)), sqrt(pow(_y, 2)), sqrt(pow(_z, 2))); }

Vector3D Vector3D::lerp(const Vector3D &v, float t) const
{ return *this + (v - *this) * t; }

float Vector3D::distance(const Vector3D &v) const
{ return (*this - v).length(); }

float Vector3D::angle(const Vector3D &v) const
{ return acos(this->dot(v) / (this->length() * v.length())); }

Vector3D Vector3D::min(const Vector3D &v) const
{ return Vector3D(std::min(_x, v._x), std::min(_y, v._y), std::min(_z, v._z)); }

Vector3D Vector3D::max(const Vector3D &v) const
{ return Vector3D(std::max(_x, v._x), std::max(_y, v._y), std::max(_z, v._z)); }

Vector3D Vector3D::clamp(const Vector3D &min, const Vector3D &max)
{ return this->min(max).max(min); }

float Vector3D::somme() const
{ return _x + _y + _z; }

float Vector3D::substract() const
{ return _x - _y - _z; }

float Vector3D::produit() const
{ return _x * _y * _z; }

float Vector3D::division() const
{ return _x / _y / _z; }
