#include "Route.h"

template <typename T>
Route<T>::Route() : head(nullptr), tail(nullptr) {}

template <typename T>
void Route<T>::Insert(const T& value) {
    Nodo<T>* freshNode = new Nodo<T>(value);
    if (head == nullptr) {
        head = freshNode;
        tail = freshNode;
    }
    else {
        freshNode->setPrevious(tail);
        tail->setNext(freshNode);
        tail = freshNode;
    }
}

template <typename T>
void Route<T>::printPoints() {
    Nodo<T>* current = head;
    while (current != nullptr) {
        T point = current->getDato();
        std::cout << "Punto: (" << point.x << ", " << point.y << ")" << std::endl;
        current = current->getNext();  // Avanza al siguiente nodo
    }
}

template <typename T>
void Route<T>::drawPoints(sf::RenderWindow& window) const {
    Nodo<T>* current = head;
    while (current != nullptr) {
        sf::CircleShape point(5.0f);
        point.setPosition(current->getDato());
        point.setFillColor(sf::Color::Red);
        window.draw(point);
        current = current->getNext();
    }
}

template <typename T>
void Route<T>::createLine(sf::VertexArray& lines) const {
    Nodo<T>* current = head;
    while (current != nullptr) {
        lines.append(sf::Vertex(current->getDato(), sf::Color::Green));
        current = current->getNext();
    }
}

template <typename T>
void Route<T>::savePointsToFile(const std::string& filename) const {
    std::ofstream outFile(filename);  // Abre el archivo para escritura

    if (!outFile) {
        std::cerr << "Error al abrir el archivo para escritura." << std::endl;
        return;
    }

    Nodo<T>* current = head;
    while (current != nullptr) {
        T point = current->getDato();
        outFile << point.x << " " << point.y << std::endl;  // Guarda las coordenadas
        current = current->getNext();  // Avanza al siguiente nodo
    }

    outFile.close();  // Cierra el archivo
    std::cout << "Coordenadas guardadas en " << filename << "." << std::endl;
}

template <typename T>
Route<T>::~Route() {
    while (head) {
        Nodo<T>* next = head->getNext();
        delete head;
        head = next;
    }
    tail = nullptr;
}

