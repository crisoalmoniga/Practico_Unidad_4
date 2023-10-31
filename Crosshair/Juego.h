#pragma once
#include <SFML/Graphics.hpp>
#include "PlayerCrosshair.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Fondo de Videojuego");

    // Cargar la textura del fondo
    sf::Texture fondoTexture;
    if (!fondoTexture.loadFromFile("D:\\Universidad - Cris\\Videojuegos\\Universidad del Litoral\\MAVI\\Practico_Unidad_3\\Unidad3_Assets\\Unidad3_Assets\\fondo.jpg")) {
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


        sf::Vector2i mousePos = sf::Mouse::getPosition();
        crosshair.Posicionar(mousePos.x, mousePos.y);

        window.clear();

        // Dibujar el fondo en toda la ventana
        window.draw(fondoSprite);

        // Dibujar el crosshair (se dibuja encima del fondo)
        crosshair.Dibujar(&window);

        window.display();
    }

    return 0;
}
