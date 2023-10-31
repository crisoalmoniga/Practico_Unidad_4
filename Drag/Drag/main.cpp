#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow ventana(sf::VideoMode(800, 600), "Puntos en las Esquinas");

    // Creación círculos rojos
    sf::CircleShape puntosRojos[4];
    for (int i = 0; i < 4; i++) {
        puntosRojos[i] = sf::CircleShape(5);
        puntosRojos[i].setFillColor(sf::Color::Red);
        puntosRojos[i].setOrigin(5, 5);
    }

    // Posiciones iniciales de las esquinas
    sf::Vector2f posicionesIniciales[4] = {
        sf::Vector2f(100, 100),
        sf::Vector2f(700, 100),
        sf::Vector2f(100, 500),
        sf::Vector2f(700, 500),
    };

    // Variables para el arrastre
    bool estaSiendoArrastrado[4] = { false };

    sf::Vector2f desplazamientos[4];

    while (ventana.isOpen()) {
        sf::Event evento;
        while (ventana.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                ventana.close();
            }

            if (evento.type == sf::Event::MouseButtonPressed) {
                if (evento.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2f posicionMouse = sf::Vector2f(evento.mouseButton.x, evento.mouseButton.y);
                    for (int i = 0; i < 4; i++) {
                        if (puntosRojos[i].getGlobalBounds().contains(posicionMouse)) {
                            estaSiendoArrastrado[i] = true;
                            desplazamientos[i] = puntosRojos[i].getPosition() - posicionMouse;
                        }
                    }
                }
            }

            if (evento.type == sf::Event::MouseButtonReleased) {
                if (evento.mouseButton.button == sf::Mouse::Left) {
                    for (int i = 0; i < 4; i++) {
                        estaSiendoArrastrado[i] = false;
                    }
                }
            }
        }

        // Arrastrar los puntos si están activos
        for (int i = 0; i < 4; i++) {
            if (estaSiendoArrastrado[i]) {
                sf::Vector2f posicionMouse = sf::Vector2f(sf::Mouse::getPosition(ventana)) + desplazamientos[i];
                posicionesIniciales[i] = posicionMouse;
            }
        }

        ventana.clear(sf::Color::Negro);

        // Dibujo los puntos en las esquinas
        for (int i = 0; i < 4; i++) {
            puntosRojos[i].setPosition(posicionesIniciales[i]);
            ventana.draw(puntosRojos[i]);
        }

        ventana.display();
    }

    return 0;
}