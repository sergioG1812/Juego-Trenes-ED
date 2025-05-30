#ifndef CARTA_H
#define CARTA_H

enum class Color { Rojo, Azul, Verde, Morado, Cafe, Naranja };

class Carta {
public:
    explicit Carta(Color color);
    Color getColor() const;
    static const char* colorACadena(Color color);

private:
    Color color;
};

#endif