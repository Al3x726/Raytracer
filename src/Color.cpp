/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-william.niarquin
** File description:
** Color
*/

#include "Color.hpp"

// operators

Color& Color::operator+(const Color &other)
{
    _r += other._r;
    _g += other._g;
    _b += other._b;
    _a += other._a;
    return *this;
}

Color& Color::operator-(const Color &other)
{
    _r -= other._r;
    _g -= other._g;
    _b -= other._b;
    _a -= other._a;
    return *this;
}

Color& Color::operator*(const Color &other)
{
    _r *= other._r;
    _g *= other._g;
    _b *= other._b;
    _a *= other._a;
    return *this;
}

Color& Color::operator/(const Color &other)
{
    if (other._r == 0) _r = 0;
    else _r /= other._r;
    if (other._g == 0) _g = 0;
    else _g /= other._g;
    if (other._b == 0) _b = 0;
    else _b /= other._b;
    if (other._a == 0) _a = 0;
    else _a /= other._a;
    return *this;
}

Color& Color::operator+(const double scalar)
{
    if (_r + scalar > 255) _r = 255;
    else _r += scalar;
    if (_g + scalar > 255) _g = 255;
    else _g += scalar;
    if (_b + scalar > 255) _b = 255;
    else _b += scalar;
    if (_a + scalar > 255) _a = 255;
    else _a += scalar;
    return *this;
}

Color& Color::operator-(const double scalar)
{
    if (_r - scalar < 0) _r = 0;
    else _r -= scalar;
    if (_g - scalar < 0) _g = 0;
    else _g -= scalar;
    if (_b - scalar < 0) _b = 0;
    else _b -= scalar;
    if (_a - scalar < 0) _a = 0;
    else _a -= scalar;
    return *this;
}

Color& Color::operator*(const double scalar)
{
    if (_r * scalar > 255) _r = 255;
    else if (_r * scalar < 0) _r = 0;
    else _r *= scalar;
    if (_g * scalar > 255) _g = 255;
    else if (_g * scalar < 0) _g = 0;
    else _g *= scalar;
    if (_b * scalar > 255) _b = 255;
    else if (_b * scalar < 0) _b = 0;
    else _b *= scalar;
    if (_a * scalar > 255) _a = 255;
    else if (_a * scalar < 0) _a = 0;
    else _a *= scalar;
    return *this;
}

Color& Color::operator/(const double scalar)
{
    if (scalar == 0) {
        _r = 0;
        _g = 0;
        _b = 0;
        _a = 0;
    } else {
        if (_r / scalar > 255) _r = 255;
        else _r /= scalar;
        if (_g / scalar > 255) _g = 255;
        else _g /= scalar;
        if (_b / scalar > 255) _b = 255;
        else _b /= scalar;
        if (_a / scalar > 255) _a = 255;
        else _a /= scalar;
    }
    return *this;
}

Color& Color::operator+=(const Color& other)
{ return *this + other; }

Color& Color::operator-=(const Color& other)
{ return *this - other; }

Color& Color::operator*=(const Color& other)
{ return *this * other; }

Color& Color::operator/=(const Color& other)
{ return *this / other; }

Color& Color::operator+=(const double scalar)
{ return *this + scalar; }

Color& Color::operator-=(const double scalar)
{ return *this - scalar; }

Color& Color::operator*=(const double scalar)
{ return *this * scalar; }

Color& Color::operator/=(const double scalar)
{ return *this / scalar; }

bool Color::operator==(const Color& other) const
{ return (_r == other._r && _g == other._g && _b == other._b && _a == other._a); }

bool Color::operator!=(const Color& other) const
{ return !(*this == other); }

std::ostream &Color::operator<<(std::ostream &os)
{
    return os << "Color(" << _r << ", " << _g << ", " << _b << ", " << _a << ")";
}



// Getters

unsigned char Color::getR() const
{ return _r; }

unsigned char Color::getG() const
{ return _g; }

unsigned char Color::getB() const
{ return _b; }

unsigned char Color::getA() const
{ return _a; }



// Setters

void Color::setR(unsigned char r)
{ _r = r; }

void Color::setG(unsigned char g)
{ _g = g; }

void Color::setB(unsigned char b)
{ _b = b; }

void Color::setA(unsigned char a)
{ _a = a; }



// Methods

void Color::gammaCorrection(double gamma)
{
    _r = (unsigned char) (255 * pow(_r / 255.0, 1.0 / gamma));
    _g = (unsigned char) (255 * pow(_g / 255.0, 1.0 / gamma));
    _b = (unsigned char) (255 * pow(_b / 255.0, 1.0 / gamma));
    _a = (unsigned char) (255 * pow(_a / 255.0, 1.0 / gamma));
}

Color Color::mix(const Color &color1, const Color &color2, double factor)
{
    return Color(
            (unsigned char) (color1._r * (1 - factor) + color2._r * factor),
            (unsigned char) (color1._g * (1 - factor) + color2._g * factor),
            (unsigned char) (color1._b * (1 - factor) + color2._b * factor),
            (unsigned char) (color1._a * (1 - factor) + color2._a * factor)
    );
}

Color Color::lerp(const Color &color1, const Color &color2, double factor)
{
    factor = std::clamp(factor, 0.0, 1.0);
    return mix(color1, color2, factor);
}

Color Color::blend(const Color& other)
{
    return Color(
            (unsigned char) (_r * (1 - other._a / 255.0) + other._r * (other._a / 255.0)),
            (unsigned char) (_g * (1 - other._a / 255.0) + other._g * (other._a / 255.0)),
            (unsigned char) (_b * (1 - other._a / 255.0) + other._b * (other._a / 255.0)),
            (unsigned char) (_a * (1 - other._a / 255.0) + other._a * (other._a / 255.0))
    );
}
