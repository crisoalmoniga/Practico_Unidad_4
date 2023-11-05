#include <SFML/Graphics.hpp>

int main() {
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "Rotaci�n de Sprite");

    sf::Texture spriteTexture;

    if (!spriteTexture.loadFromFile("cuad_red.png")) {
        return 1; // Salir del programa en caso de error de carga de textura
    }

    // Crear un sprite con la textura del sprite cargado
    sf::Sprite sprite(spriteTexture);

    // Establecer la posici�n inicial del sprite en (400, 300)
    sprite.setPosition(400, 300);

    // Velocidad de rotaci�n en grados por segundo
    float rotationSpeed = 5.0f; // grados por segundo

    // Se definen los l�mites para el tama�o de la ventana
    const int minWidth = 100;
    const int minHeight = 100;
    const int maxWidth = 1000;
    const int maxHeight = 1000;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::Resized) {
                // Comprobar si el tama�o de la ventana est� dentro de los l�mites
                int newWidth = std::max(minWidth, std::min(maxWidth, event.size.width);
                int newHeight = std::max(minHeight, std::min(maxHeight, event.size.height);
                window.setSize(sf::Vector2u(newWidth, newHeight));
            }
        }

        window.clear();

        // Cambiar el �ngulo de rotaci�n del sprite
        float deltaTime = 0.016f; // Aproximadamente 60 fotogramas por segundo (ajustado seg�n necesidad)
        float rotation = sprite.getRotation();
        rotation += rotationSpeed * deltaTime;
        sprite.setRotation(rotation);

        window.draw(sprite);

        window.display();
    }

    return 0;
}
