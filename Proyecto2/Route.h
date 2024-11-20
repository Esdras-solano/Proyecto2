#pragma once
#include "Nodo.cpp"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

template <typename T>
class Route
{
private:
    Nodo<T>* head;
    Nodo<T>* tail;

public:
    Route();
    void Insert(const T& value);
    void printPoints();
    void drawPoints(sf::RenderWindow& window) const;
    void createLine(sf::VertexArray& lines) const;
    void savePointsToFile(const std::string& filename) const;
    ~Route();
};


