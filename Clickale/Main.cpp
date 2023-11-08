#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <ctime>
#include <cstdlib>

//Hay varias cosas que investigué y busqué con GPT para hacerlas ya que no sabia como hacerlas, el srand y el método para controlar la aparición de los enemigos por ejemplo.

using namespace sf;

class Et {

public:

    // Constructor de la clase "Et"
    Et(Texture& texture, float scale) {
        sprite.setTexture(texture);
        sprite.setScale(scale, scale);
        sprite.setPosition(rand() % 800, rand() % 800);  // Posición inicial aleatoria
        temporizador = Clock();  // Inicializa el temporizador
        vivo = true;
    }


    void update() {
        if (vivo && temporizador.getElapsedTime().asSeconds() > 0.9) {
        }
    }

    Sprite sprite;  // Sprite del enemigo
    bool vivo;  // Indica si el enemigo está vivo o muerto
    Clock temporizador;  // Temporizador para la lógica del enemigo
};

int main() {

    srand(time(0));

    Texture texture;
    Texture miraTextura;
    Texture fondoTexture;

 
    texture.loadFromFile("et.png");  // Textura del enemigo
    miraTextura.loadFromFile("crosshair.png");  // Textura del cursor
    fondoTexture.loadFromFile("fondo.jpg");  // Textura del fondo - No entiendo porque no funciona, copié la modalidad del ejercicio de la unidad 3 pero no me funca - SOLUCIONADO: FALTABA LA DECLARACION DEL SPRITE

    // Configuración del sprite de la mira
    Sprite miraSprite(miraTextura);
    miraSprite.setScale(0.2f, 0.2f);  // Escala el cursor
    miraSprite.setOrigin(miraSprite.getGlobalBounds().width / 2, miraSprite.getGlobalBounds().height / 2);

    RenderWindow App(VideoMode(900, 900), "Clickale");

    std::vector<Et> etList;  // Vector para almacenar los enemigos
    int etMuertos = 0;  // Contador de enemigos derrotados

    Clock etAppearTimer;  // Temporizador para la aparición de enemigos
    Time etDisappearTime = seconds(0.9);  // Tiempo entre apariciones de enemigos

    Sprite fondoSprite(fondoTexture);

    while (App.isOpen()) {
        Event event;
        while (App.pollEvent(event)) {
            if (event.type == Event::Closed) {
                App.close();
            }
            else if (event.type == Event::MouseMoved) {
                miraSprite.setPosition(event.mouseMove.x, event.mouseMove.y);
            }
            else if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                // Comprueba si se hizo clic en un enemigo
                for (Et& et : etList) {
                    if (et.vivo && et.sprite.getGlobalBounds().contains(miraSprite.getPosition())) {
                        et.vivo = false;  // El enemigo muere
                        etMuertos++;  // Contador de enemigos muertos, suma de a uno
                    }
                }
            }
        }

        // Controlador de aparicion de enemigos
        if (etAppearTimer.getElapsedTime() >= etDisappearTime) {
            etList.emplace_back(texture, 0.4f);  // Añade un nuevo enemigo al vector
            etAppearTimer.restart();  // Reinicia el temporizador
        }

        App.clear();

        // Dibuja el fondo en toda la ventana
        App.draw(fondoSprite);

        // Dibuja los enemigos vivos en la ventana
        for (Et& et : etList) {
            if (et.vivo) {
                et.update();  // Actualiza la lógica del enemigo
                et.sprite.setScale(0.1f, 0.1f);  // Escala el sprite del enemigo
                App.draw(et.sprite);  // Dibuja el enemigo
            }
        }

        // Dibuja el cursor
        App.draw(miraSprite);

        App.display();

        // Cierra la ventana si se derrotaron 5 enemigos
        if (etMuertos >= 5) {
            App.close();
        }
    }

    return 0;
}
