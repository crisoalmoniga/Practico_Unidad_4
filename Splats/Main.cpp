#include <SFML/Graphics.hpp>
#include <vector>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Splats");
    sf::Texture circuloRojoTexture; // Declaración de la textura para el círculo rojo
    sf::Texture circuloAzulTexture; // Declaración de la textura para el círculo azul
    circuloRojoTexture.loadFromFile("rcircle.png"); // Carga la textura del círculo rojo desde un archivo
    circuloAzulTexture.loadFromFile("bcircle.png"); // Carga la textura del círculo azul desde un archivo

    std::vector<sf::CircleShape> circulos; // Vector para almacenar los círculos

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::MouseButtonPressed) // Si se presiona un botón del mouse
            {
                int x = event.mouseButton.x; // Obtiene la posición X del mouse
                int y = event.mouseButton.y; // Obtiene la posición Y del mouse

                if (event.mouseButton.button == sf::Mouse::Left) // Si se presiona el botón izquierdo del mouse
                {
                    sf::CircleShape circuloRojo(30); // Crea un círculo rojo con radio 30
                    circuloRojo.setTexture(&circuloRojoTexture); // Aplica la textura de círculo rojo
                    circuloRojo.setPosition(x, y); // Establece la posición del círculo en las coordenadas del clic
                    circulos.push_back(circuloRojo); // Agrega el círculo al vector
                }
                else if (event.mouseButton.button == sf::Mouse::Right) // Si se presiona el botón derecho del mouse
                {
                    sf::CircleShape circuloAzul(30); // Crea un círculo azul con radio 30
                    circuloAzul.setTexture(&circuloAzulTexture); // Aplica la textura de círculo azul
                    circuloAzul.setPosition(x, y); // Establece la posición del círculo en las coordenadas del clic
                    circulos.push_back(circuloAzul); // Agrega el círculo al vector
                }
            }
        }

        window.clear();

        for (const sf::CircleShape& circulo : circulos) // Dibuja todos los círculos en el vector
        {
            window.draw(circulo);
        }

        window.display();
    }

    return 0;
}
