#include <SFML/Graphics.hpp>
#include <vector>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Splats");
    sf::Texture circuloRojoTexture; // Declaraci�n de la textura para el c�rculo rojo
    sf::Texture circuloAzulTexture; // Declaraci�n de la textura para el c�rculo azul
    circuloRojoTexture.loadFromFile("rcircle.png"); // Carga la textura del c�rculo rojo desde un archivo
    circuloAzulTexture.loadFromFile("bcircle.png"); // Carga la textura del c�rculo azul desde un archivo

    std::vector<sf::CircleShape> circulos; // Vector para almacenar los c�rculos

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::MouseButtonPressed) // Si se presiona un bot�n del mouse
            {
                int x = event.mouseButton.x; // Obtiene la posici�n X del mouse
                int y = event.mouseButton.y; // Obtiene la posici�n Y del mouse

                if (event.mouseButton.button == sf::Mouse::Left) // Si se presiona el bot�n izquierdo del mouse
                {
                    sf::CircleShape circuloRojo(30); // Crea un c�rculo rojo con radio 30
                    circuloRojo.setTexture(&circuloRojoTexture); // Aplica la textura de c�rculo rojo
                    circuloRojo.setPosition(x, y); // Establece la posici�n del c�rculo en las coordenadas del clic
                    circulos.push_back(circuloRojo); // Agrega el c�rculo al vector
                }
                else if (event.mouseButton.button == sf::Mouse::Right) // Si se presiona el bot�n derecho del mouse
                {
                    sf::CircleShape circuloAzul(30); // Crea un c�rculo azul con radio 30
                    circuloAzul.setTexture(&circuloAzulTexture); // Aplica la textura de c�rculo azul
                    circuloAzul.setPosition(x, y); // Establece la posici�n del c�rculo en las coordenadas del clic
                    circulos.push_back(circuloAzul); // Agrega el c�rculo al vector
                }
            }
        }

        window.clear();

        for (const sf::CircleShape& circulo : circulos) // Dibuja todos los c�rculos en el vector
        {
            window.draw(circulo);
        }

        window.display();
    }

    return 0;
}
