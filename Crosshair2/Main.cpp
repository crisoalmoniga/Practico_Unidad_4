#include <SFML/Graphics.hpp>

int main() {
    // Crea la ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "Crosshair");

    // Carga la textura del sprite desde archivo, siempre poner el png dentro de carpeta del proyecto
    sf::Texture texture;
    if (!texture.loadFromFile("crosshair2.png"))
        return 1; // Aviso de error de carga

    // Sprite con la textura
    sf::Sprite sprite(texture);

    // Centra el sprite en la ventana
    sprite.setPosition((window.getSize().x - sprite.getGlobalBounds().width) / 2,
        (window.getSize().y - sprite.getGlobalBounds().height) / 2);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            
            if (event.type == sf::Event::Closed)
                window.close();
        }

        
        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}
