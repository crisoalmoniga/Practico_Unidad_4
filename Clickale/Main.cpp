#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Clickale");

    // Cargar la textura del fondo, siempre actualizar desde la ruta específica
    sf::Texture fondoTexture;
    if (!fondoTexture.loadFromFile("fondo.jpg")) {
        return 1; // Si la ruta falla, tira error 1.
    }

    // Crear un sprite para el fondo
    sf::Sprite fondoSprite(fondoTexture);

    // Cargar la textura del crosshair
    sf::Texture crosshairTexture;
    if (!crosshairTexture.loadFromFile("crosshair.png")) {
        return 1; // Si la ruta del crosshair falla, tira error 1.
    }

    // Crea un sprite para el crosshair
    sf::Sprite crosshairSprite(crosshairTexture);

    // Ajusta el punto de origen del crosshair al centro
    crosshairSprite.setOrigin(crosshairSprite.getLocalBounds().width / 2, crosshairSprite.getLocalBounds().height / 2);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Obtener la posición del puntero del mouse en relación a la ventana
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        crosshairSprite.setPosition(static_cast<sf::Vector2f>(mousePosition));

        window.clear();

        // Dibujar el fondo en toda la ventana
        window.draw(fondoSprite);

        // Dibujar el crosshair en la posición del puntero del mouse
        window.draw(crosshairSprite);

        window.display();
    }

    return 0;
}
