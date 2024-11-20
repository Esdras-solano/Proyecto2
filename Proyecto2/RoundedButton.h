#pragma once
#include <SFML/Graphics.hpp>
class RoundedButton {
private:
    sf::RectangleShape mainRect;  // El �nico rect�ngulo del bot�n
    bool clicked;                 // Estado para saber si el bot�n fue cliqueado

public:
    // Constructor
    RoundedButton(float x, float y, float width, float height, sf::Color color);

    // Funci�n para dibujar el bot�n en la ventana
    void draw(sf::RenderWindow& window);

    // Funci�n para detectar si un punto est� dentro del bot�n
    bool contains(float x, float y);

    // Funci�n para manejar el evento de clic
    void onClick();

    // Funci�n para saber si el bot�n est� en estado clicado
    bool isClicked() const;
};
