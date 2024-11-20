#include "RoundedButton.h"

// Constructor
RoundedButton::RoundedButton(float x, float y, float width, float height, sf::Color color)
    : clicked(false) {  // Inicializamos 'clicked' en false
    // Rect�ngulo principal (bot�n)
    mainRect.setSize(sf::Vector2f(width, height));
    mainRect.setPosition(x, y);
    mainRect.setFillColor(color);
}

// Funci�n para dibujar el bot�n en la ventana
void RoundedButton::draw(sf::RenderWindow& window) {
    window.draw(mainRect);
}

// Funci�n para detectar si un punto est� dentro del bot�n
bool RoundedButton::contains(float x, float y) {
    sf::FloatRect bounds = mainRect.getGlobalBounds();
    return bounds.contains(x, y);
}

// Funci�n para manejar el evento de clic
void RoundedButton::onClick() {
    clicked = !clicked;  // Cambiamos el estado de clic al opuesto
}

// Funci�n para saber si el bot�n est� en estado clicado
bool RoundedButton::isClicked() const {
    return clicked;
}

