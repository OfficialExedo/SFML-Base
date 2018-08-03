#pragma once

#include <map>
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class AssetManager
{
    public:
        void loadTexture(std::string name, std::string filePath);
        const sf::Texture& getTexture(std::string name);
        void disposeTexture(std::string name);

        void loadFont(std::string name, std::string filePath);
        const sf::Font& getFont(std::string name);
        void disposeFont(std::string name);

    private:
        std::map<std::string, sf::Texture> textures;
        std::map<std::string, sf::Font> fonts;
};