/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-william.niarquin
** File description:
** ImagePPM
*/

#include "ImagePPM.hpp"


// Methods

void ImagePPM::createImage(const char *path)
{
    std::string filepath = path + std::string(".ppm");;
    std::ofstream file(filepath);


    if (file.fail()) throw std::runtime_error("Error: Can't create file");

    file << "P3" << std::endl;
    file << _width << " " << _height << std::endl;
    file << "255" << std::endl;

    for (size_t i = 0; i < _pixels.size() ; i++) {
        file    << (int)_pixels.at(i)->getR() << " "
                << (int)_pixels.at(i)->getG() << " "
                << (int)_pixels.at(i)->getB() << std::endl;
    }
    file.close();
}


// Setters

void ImagePPM::setSize(int width, int height)
{
    _width = width;
    _height = height;
}

void ImagePPM::setWidth(int width)
{ _width = width; }

void ImagePPM::setHeight(int height)
{ _height = height;}

void ImagePPM::setPixels(std::vector<Color *> pixels)
{ _pixels = pixels; }

void ImagePPM::setPixel(int x, int y, Color *color)
{ _pixels.push_back(color); }

void ImagePPM::setPixel(int index, Color *color)
{ _pixels.at(index) = color; }


// Getters

std::vector<Color *> ImagePPM::getPixels() const
{ return _pixels; }

Color *ImagePPM::getPixel(int x, int y) const
{ return _pixels.at(x + y * _width); }

Color *ImagePPM::getPixel(int index) const
{ return _pixels.at(index); }

int ImagePPM::getWidth() const
{ return _width; }

int ImagePPM::getHeight() const
{ return _height; }
