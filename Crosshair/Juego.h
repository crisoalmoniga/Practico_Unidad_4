#pragma once
#include <SFML/Graphics.hpp>
#include "PlayerCrosshair.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Fondo de Videojuego");

    // Cargar la textura del fondo
    sf::Texture fondoTexture;
    if (!fondoTexture.loadFromFile("D:\\Universidad - Cris\\Videojuegos\\Universidad del Litoral\\MAVI\\Practica_Unidad_4\\Practico_Unidad_4\\Crosshair\\fondo.jpg")) {
        return 1; // Si la ruta falla, tira error 1.
    }

    // Crear un sprite para el fondo
    sf::Sprite fondoSprite(fondoTexture);

    // Crear una instancia de PlayerCrosshair
    PlayerCrosshair crosshair;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }


        // Configurar el origen en el centro del sprite NO SE CENTRAAAAAAAA
        sf::Vector2u size = _crossTex.getSize();
        _crossSprite.setOrigin(size.x / 1.0f, size.y / 1.0f);

        window.clear();

        // Dibujar el fondo en toda la ventana
        window.draw(fondoSprite);

        // Dibujar el crosshair (se dibuja encima del fondo)
        crosshair.Dibujar(&window);

        window.display();
    }

    return 0;
}
