#include <SFML/Graphics.hpp>


int main() {
    // Crear la ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "Clickable");

    // Cargar la textura del fondo
    sf::Texture fondoTexture;
    if (!fondoTexture.loadFromFile("fondo.jpg")) {
        return 1; // Si la carga del fondo falla, tira error 1.
    }

    // Crear un sprite para el fondo
    sf::Sprite fondoSprite(fondoTexture);

    // Cargar la textura del crosshair
    sf::Texture crosshairTexture;
    if (!crosshairTexture.loadFromFile("crosshair.png")) {
        return 1; // Si la carga del crosshair falla, tira error 1.
    }

    // Crear un sprite para el crosshair y ajustar su punto de origen al centro
    sf::Sprite crosshairSprite(crosshairTexture);
    crosshairSprite.setOrigin(crosshairSprite.getLocalBounds().width / 2, crosshairSprite.getLocalBounds().height / 2);

    // Cargar la textura del ET
    sf::Texture etTexture;
    if (!etTexture.loadFromFile("et.png")) {
        return 1; // Si la carga de "et.png" falla, tira error 1.
    }

    // Crear un sprite para ET y establecer su posición inicial
    sf::Sprite etSprite(etTexture);
    etSprite.setPosition(5, 5);

    // Escalar el sprite ET a 100x100 píxeles
    etSprite.setScale(100.0f / etSprite.getGlobalBounds().width, 100.0f / etSprite.getGlobalBounds().height);



    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Verificar si se hizo clic en "et.png"
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // Obtener la posición del clic del mouse y convertirla a coordenadas
                    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                    sf::Vector2f worldMousePosition = window.mapPixelToCoords(mousePosition);

                    // Verificar si el clic se realizó dentro de la región de "et.png"
                    if (etSprite.getGlobalBounds().contains(worldMousePosition)) {
                        // Ocultar "et.png" al hacer clic sobre él
                        etSprite.setColor(sf::Color(0, 0, 0, 0)); // Establece el alpha a 0 para hacerlo transparente

                    }
                }
            }
        }

        // Obtener la posición del puntero del mouse en relación a la ventana y mover el crosshair
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        crosshairSprite.setPosition(static_cast<sf::Vector2f>(mousePosition));

        window.clear();

        // Dibujar el fondo en toda la ventana
        window.draw(fondoSprite);

        // Dibujar el "et.png"
        window.draw(etSprite);

        // Dibujar el crosshair
        window.draw(crosshairSprite);

        window.display();
    }

    return 0;
}
