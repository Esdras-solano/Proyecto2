#include "RoundedButton.h"

// Constructor
RoundedButton::RoundedButton(float x, float y, float width, float height, sf::Color color)
    : clicked(false) {  // Inicializamos 'clicked' en false
    // Rectángulo principal (botón)
    mainRect.setSize(sf::Vector2f(width, height));
    mainRect.setPosition(x, y);
    mainRect.setFillColor(color);
}

// Función para dibujar el botón en la ventana
void RoundedButton::draw(sf::RenderWindow& window) {
    window.draw(mainRect);
}

// Función para detectar si un punto está dentro del botón
bool RoundedButton::contains(float x, float y) {
    sf::FloatRect bounds = mainRect.getGlobalBounds();
    return bounds.contains(x, y);
}

// Función para manejar el evento de clic
void RoundedButton::onClick() {
    clicked = !clicked;  // Cambiamos el estado de clic al opuesto
}

// Función para saber si el botón está en estado clicado
bool RoundedButton::isClicked() const {
    return clicked;
}

