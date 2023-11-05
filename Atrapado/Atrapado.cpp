#include <SFML/Graphics.hpp>

int main(){

    sf::RenderWindow window(sf::VideoMode(800, 600), "Figura M�vil");

    // Cargar las texturas para el cuadrado amarillo y el c�rculo rojo
    sf::Texture cuadradoTexture;
    sf::Texture cuadradoTexture2;
    cuadradoTexture.loadFromFile("cuad_yellow.png");
    cuadradoTexture2.loadFromFile("cuad_red.png");

    // Crear un sprite para representar la figura, inicialmente con la textura del cuadrado
    sf::Sprite figuraSprite;
    figuraSprite.setTexture(cuadradoTexture);

    // Definir la velocidad de movimiento y una variable para rastrear si el bot�n del mouse est� presionado
    const float velocidadMovimiento = 5.0f;
    bool mousePresionado = false;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Space)
                {
                    // Cambiar entre el cuadrado y el c�rculo al presionar la barra espaciadora
                    if (figuraSprite.getTexture() == &cuadradoTexture)
                        figuraSprite.setTexture(cuadradoTexture2);
                    else
                        figuraSprite.setTexture(cuadradoTexture);
                }
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    // Comprobar si el clic del mouse ocurri� dentro del sprite
                    if (figuraSprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                    {
                        mousePresionado = true;
                    }
                }
            }

            if (event.type == sf::Event::MouseButtonReleased)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    mousePresionado = false;
                }
            }
        }

        if (mousePresionado)
        {
            // Mover el sprite a la posici�n del mouse mientras se mantiene presionado el bot�n del mouse
            figuraSprite.setPosition(sf::Mouse::getPosition(window).x - figuraSprite.getGlobalBounds().width / 2, sf::Mouse::getPosition(window).y - figuraSprite.getGlobalBounds().height / 2);
        }

        // Limitar la posici�n del sprite para que no salga de la ventana
        if (figuraSprite.getPosition().x < 0)
        {
            figuraSprite.setPosition(0, figuraSprite.getPosition().y);
        }
        if (figuraSprite.getPosition().y < 0)
        {
            figuraSprite.setPosition(figuraSprite.getPosition().x, 0);
        }
        if (figuraSprite.getPosition().x + figuraSprite.getGlobalBounds().width > window.getSize().x)
        {
            figuraSprite.setPosition(window.getSize().x - figuraSprite.getGlobalBounds().width, figuraSprite.getPosition().y);
        }
        if (figuraSprite.getPosition().y + figuraSprite.getGlobalBounds().height > window.getSize().y)
        {
            figuraSprite.setPosition(figuraSprite.getPosition().x, window.getSize().y - figuraSprite.getGlobalBounds().height);
        }

        // Limpiar la ventana, dibujar el sprite y mostrar la ventana
        window.clear();
        window.draw(figuraSprite);
        window.display();
    }

    return 0;
}
