#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Route.cpp"

#include <SFML/Graphics.hpp>

class RoundedButton {
private:
    sf::RectangleShape mainRect;  // El �nico rect�ngulo del bot�n
    bool clicked;                 // Estado para saber si el bot�n fue cliqueado

public:
    // Constructor
    RoundedButton(float x, float y, float width, float height, sf::Color color)
        : clicked(false) {  // Inicializamos 'clicked' en false
        // Rect�ngulo principal (bot�n)
        mainRect.setSize(sf::Vector2f(width, height));
        mainRect.setPosition(x, y);
        mainRect.setFillColor(color);
    }

    // Funci�n para dibujar el bot�n en la ventana
    void draw(sf::RenderWindow& window) {
        window.draw(mainRect);
    }

    // Funci�n para detectar si un punto est� dentro del bot�n
    bool contains(float x, float y) {
        sf::FloatRect bounds = mainRect.getGlobalBounds();
        return bounds.contains(x, y);
    }

    // Funci�n para manejar el evento de clic
    void onClick() {
        clicked = !clicked;  // Cambiamos el estado de clic al opuesto
    }

    // Funci�n para saber si el bot�n est� en estado clicado
    bool isClicked() const {
        return clicked;
    }
};


bool loadMap(sf::Texture& texture, sf::Sprite& sprite) {
    if (!texture.loadFromFile("Map.png")) {
        std::cerr << "Error al cargar la imagen." << std::endl;
        return false;
    }
    sprite.setTexture(texture);
    return true;
}

void extension(sf::RectangleShape& background, sf::RectangleShape& separatorLine) {
    background.setPosition(1000, 0);
    background.setFillColor(sf::Color(226,241,231));

    separatorLine.setSize(sf::Vector2f(2, 1000));
    separatorLine.setPosition(1000, 0);
    separatorLine.setFillColor(sf::Color::Black);
}

int main() {
    sf::RenderWindow window(sf::VideoMode(1250, 1000), "Map");
    window.clear(sf::Color::White);

    std::string inputText = "";  // Almacena el texto ingresado

    //Creamos los botones
    RoundedButton createOtherRoute(30, 750, 200, 50, sf::Color(36,54,66));
    RoundedButton Create(385, 860, 200, 50, sf::Color(36, 54, 66));

    //declaramos variables
    sf::Text nameRoute, otherRouteText, createText;
    sf::Font font;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::RectangleShape background(sf::Vector2f(250, 1000));
    sf::RectangleShape separatorLine;

    //Cargamos la fuente
    if (!font.loadFromFile("arial.ttf")) {
        std::cout << "Error cargando la fuente\n";
        return 1;
    }

    createText.setFont(font);
    createText.setString("Crear");
    createText.setCharacterSize(24);
    createText.setFillColor(sf::Color::White);
    createText.setPosition(450, 870);

    //Texto de agregar otra ruta
    otherRouteText.setFont(font);
    otherRouteText.setString("Agregar ruta");
    otherRouteText.setCharacterSize(24);
    otherRouteText.setFillColor(sf::Color::White);
    otherRouteText.setPosition(60, 760);

    // Texto que dice "Ingrese el texto:"
    nameRoute.setFont(font);
    nameRoute.setString("Ingrese el nombre de la Ruta");
    nameRoute.setCharacterSize(24);
    nameRoute.setFillColor(sf::Color::Black);
    nameRoute.setPosition(330, 745);  // Posici�n en la ventana

    // Cuadro de texto donde se mostrar� el texto ingresado
    sf::Text textDisplay("", font, 24);
    textDisplay.setFillColor(sf::Color::White);
    textDisplay.setPosition(340, 785);  // Debajo del mensaje

    // Rect�ngulo que act�a como cuadro de entrada
    sf::RectangleShape inputBox(sf::Vector2f(300, 50));  // Tama�o del cuadro
    inputBox.setFillColor(sf::Color(50, 50, 50));  // Color de fondo del cuadro
    inputBox.setPosition(340, 785);  // Posici�n del cuadro

    //Estados para las ventanas
    bool textEntryMode = false;
    bool otherRouteMode = false;

    //Cargamos el mapa
    if (!loadMap(texture, sprite)) {
        return 1;
    }
    extension(background, separatorLine);
    //creamos lista
    Route<sf::Vector2f> pointsRoute;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {

                    sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);

                    if (!otherRouteMode && createOtherRoute.contains(mousePos.x, mousePos.y)) {
                        otherRouteMode = true;
                        textEntryMode = true;  // Inicia el modo de entrada de texto
                        inputText = "";  // Reinicia el texto
                        std::cout << "Modo de ingreso de texto activado." << std::endl;
                    }

                    if (createOtherRoute.contains(mousePos.x, mousePos.y)) {
                        createOtherRoute.onClick();  // Cambiamos el estado del bot�n
                    }
                    if (Create.contains(mousePos.x, mousePos.y)) {
                        Create.onClick();
                        if (textEntryMode) {
                            // Cuando se hace clic en el bot�n Create, imprime el texto ingresado
                            std::cout << "Texto ingresado: " << inputText << std::endl;
                            textEntryMode = false;  // Salimos del modo de entrada de texto
                            otherRouteMode = false;
                            pointsRoute.savePointsToFile("coordenadas.txt");
                        }
                    }
                    if (createOtherRoute.isClicked() && mousePos.x >= 0 && mousePos.x <= 1000 && mousePos.y >= 0 && mousePos.y <= 720) {
                        pointsRoute.Insert(mousePos);
                        pointsRoute.printPoints();
                    }
                }
            }

            // Si estamos en modo de entrada de texto, capturar la entrada de teclado
            if (textEntryMode && event.type == sf::Event::TextEntered) {
                if (event.text.unicode == 8) {  // Si presiona Retroceso (unicode 8)
                    if (!inputText.empty()) {
                        inputText.pop_back();  // Elimina el �ltimo car�cter
                    }
                }
                else if (event.text.unicode < 128) {  // Solo acepta caracteres ASCII
                    // Agrega el car�cter al texto ingresado
                    inputText += static_cast<char>(event.text.unicode);
                }
                // Actualiza el texto que se muestra en el cuadro de entrada
                textDisplay.setString(inputText);
            }

        }

        window.clear(sf::Color(98,149,132));
        window.draw(sprite);
        window.draw(background);
        window.draw(separatorLine);

        createOtherRoute.draw(window);
        window.draw(otherRouteText);

        if (otherRouteMode) {
            window.draw(nameRoute);
            window.draw(inputBox);
            window.draw(textDisplay);
            window.draw(otherRouteText);
            Create.draw(window);
            window.draw(createText);
            pointsRoute.drawPoints(window);
            sf::VertexArray lines(sf::LinesStrip);
            pointsRoute.createLine(lines);
            window.draw(lines);
        }

        window.display();
    }

    return 0;
}
