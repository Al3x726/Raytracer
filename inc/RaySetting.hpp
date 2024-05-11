/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-william.niarquin
** File description:
** class global RaySetting
*/

#ifndef RAYSETTING_HPP_
    #define RAYSETTING_HPP_


    #ifndef _GLIBCXX_STRING
        #include <string>
    #endif


/**
 * @brief [RaySetting] class it's abstract class of the ray setting
 * This class is used to define Camera and Light
 */
class RaySetting {
    public:
        /**
         * @brief Destroy the RaySetting object (it's virtual because it's abstract class)
         */
        virtual ~RaySetting() = default;

        /**
         * @brief Get the Type object
         * 
         * @return std::string
         */
        virtual std::string getType() = 0;
};

#endif /* !RAYSETTING_HPP_ */
