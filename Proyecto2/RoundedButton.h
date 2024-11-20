#pragma once
#include <SFML/Graphics.hpp>
class RoundedButton {
private:
    sf::RectangleShape mainRect;  // El único rectángulo del botón
    bool clicked;                 // Estado para saber si el botón fue cliqueado

public:
    // Constructor
    RoundedButton(float x, float y, float width, float height, sf::Color color);

    // Función para dibujar el botón en la ventana
    void draw(sf::RenderWindow& window);

    // Función para detectar si un punto está dentro del botón
    bool contains(float x, float y);

    // Función para manejar el evento de clic
    void onClick();

    // Función para saber si el botón está en estado clicado
    bool isClicked() const;
};
