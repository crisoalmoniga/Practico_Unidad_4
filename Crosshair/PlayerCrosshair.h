#include <SFML/Graphics.hpp>

class PlayerCrosshair {
    sf::Texture _crossTex;
    sf::Sprite _crossSprite;

public:
    PlayerCrosshair() {
        _crossTex.loadFromFile("D:\\Universidad - Cris\\Videojuegos\\Universidad del Litoral\\MAVI\\Practica_Unidad_4\\Practico_Unidad_4\\Unidad3_Assets\\Unidad3_Assets\\rcircle.png");
        _crossSprite.setTexture(_crossTex);
        _crossSprite.setScale(0.1f, 0.1f);

        // Configurar el origen en el centro del sprite
        sf::Vector2u size = _crossTex.getSize();
        _crossSprite.setOrigin(size.x / 2.0f, size.y / 2.0f);
    }

    void Dibujar(sf::RenderWindow* wnd) {
        wnd->draw(_crossSprite);
    }

    void PosicionarEnCentro(sf::RenderWindow* wnd) {
        // Obtener la posición del mouse en relación a la ventana
        sf::Vector2i mousePos = sf::Mouse::getPosition(*wnd);

        // Configurar la posición del sprite en función de la posición del mouse
        _crossSprite.setPosition(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
    }
};

