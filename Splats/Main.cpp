#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Splats");
    sf::Texture redCircle;
    sf::Texture blueCircle;
    redCircle.loadFromFile("rcircle.png"); // Carga la textura roja desde la ruta espec�fica
    blueCircle.loadFromFile("rcircleb.png"); // Carga la textura azul desde la ruta espec�fica
    sf::Sprite sprite;