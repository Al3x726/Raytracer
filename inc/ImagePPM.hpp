/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-william.niarquin
** File description:
** ImagePPM
*/

#ifndef IMAGEPPM_HPP_
    #define IMAGEPPM_HPP_

    #include "raytracer.hpp"
    #include "Color.hpp"
    #include <fstream>


/**
 * @brief [ImagePPM] class of the image (PPM format) (P3) (ASCII) (RGB)
 * This class is used to define the image
 * and to define the methods that the image must have
 * (ex: createImage, ...)
 *
 * @param _width: the width of the image (the number of columns)
 * @param _height: the height of the image (the number of lines)
 * @param _pixels: the pixels of the image (vector of Color)
 */
class ImagePPM {
    public:
        /**
         * @brief Default construct a new Image PP
         */
        ImagePPM(): _width(0), _height(0) {};

        /**
         * @brief Construct a new Image PPM
         *
         * @param width of the image
         * @param height of the image
         */
        ImagePPM(int width, int height): _width(width), _height(height) {};

        /**
         * @brief Copy construct a new Image PPM
         *
         * @param copy
         */
        ImagePPM(const ImagePPM &copy) = default;

        /**
         * @brief Construct a new Image PPM
         *
         * @param other
         */
        ImagePPM(ImagePPM &&other) = default;

        /**
         * @brief Destroy the Image PPM
         */
        ~ImagePPM() = default;



        /**
         * @brief Copy a ImagePPM
         *
         * @param copy
         * @return ImagePPM
         */
        ImagePPM &operator=(const ImagePPM &copy) = default;

        /**
         * @brief Move a ImagePPM
         *
         * @param other
         * @return ImagePPM
        */
        ImagePPM &operator=(ImagePPM &&other) = default;



        /**
         * @brief Create a Image object when the raytracer is finished
         *
         * @param path of the image to create
         */
        void createImage(const char *path);



        /**
         * @brief Set the Size value
         *
         * @param width of the image
         * @param height of the image
         */
        void setSize(int width, int height);

        /**
         * @brief Set the Width value
         *
         * @param width of the image
         */
        void setWidth(int width);

        /**
         * @brief Set the Height value
         *
         * @param height of the image
         */
        void setHeight(int height);
        // [setPixels] Set the pixels of the image
        // \param pixels: the pixels of the image
        /**
         * @brief Set the Pixels value
         *
         * @param pixels of the image
         */
        void setPixels(std::vector<Color*> pixels);

        /**
         * @brief Set the Pixel value
         *
         * @param x: position of the pixel
         * @param y: position of the pixel
         * @param color of the pixel
         */
        void setPixel(int x, int y, Color *color);

        /**
         * @brief Set the Pixel value
         *
         * @param index of the pixel
         * @param color of the pixel
         */
        void setPixel(int index, Color *color);



        /**
         * @brief Get the Width value
         *
         * @return int
         */
        int getWidth() const;

        /**
         * @brief Get the Height value
         *
         * @return int
         */
        int getHeight() const;

        /**
         * @brief Get the Pixels value
         *
         * @return std::vector<Color *>
         */
        std::vector<Color *> getPixels() const;

        /**
         * @brief Get the Pixel value
         *
         * @param x: position of the pixel
         * @param y: position of the pixel
         * @return Color*
         */
        Color *getPixel(int x, int y) const;

        /**
         * @brief Get the Pixel value
         *
         * @param index of the pixel
         * @return Color*
         */
        Color *getPixel(int index) const;

    private:
        int _width;
        int _height;
        std::vector<Color *> _pixels;
};

#endif /* !IMAGEPPM_HPP_ */
