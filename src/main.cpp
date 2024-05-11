/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-william.niarquin
** File description:
** main
*/

#include "raytracer.hpp"
#include "Core.hpp"

int main(int ac, const char *av[])
{
    if (ac != 2) {
        std::cerr << "Usage: ./raytracer <SCENE_FILE>\n\tSCENE_FILE: scene configuration" << std::endl;
        return 84;
    }
    if (ac == 2 && strcmp(av[1], "--help") == 0) {
        std::cout << "USAGE\n\t./raytracer <SCENE_FILE>\n\nDESCRIPTION\n\tSCENE_FILE\tscene configuration file in cfg format" << std::endl;
        return 0;
    }
    Core core(av[1]);
}
#include <SFML/Graphics.hpp>
