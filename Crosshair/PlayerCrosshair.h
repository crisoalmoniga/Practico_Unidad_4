#pragma once

#include <SFML/Graphics.hpp>

class PlayerCrosshair {
    sf::Texture _crossTex;
    sf::Sprite _crossSprite;

public:
    PlayerCrosshair() {
        _crossTex.loadFromFile("D:\\Universidad - Cris\\Videojuegos\\Universidad del Litoral\\MAVI\\Practica_Unidad_4\\Practico_Unidad_4\\Unidad3_Assets\\Unidad3_Assets\\rcircle.png");
        _crossSprite.setTexture(_crossTex);
        _crossSprite.setScale(0.1f, 0.1f);
    }

    void Dibujar(sf::RenderWindow* wnd) {
        wnd->draw(_crossSprite);
    }

    void Posicionar(float x, float y) {
        _crossSprite.setPosition(x, y);
    }
};
