#ifndef BARAJA_H
#define BARAJA_H
#include <vector>
#include "Carta.h"
using namespace std;

class Baraja {
public:
    Baraja();
    void inicializar();
    void barajar();
    Carta robarCarta();
    void reponerDesdeDescarte();
    void descartar(const std::vector<Carta>& cartas);
    bool estaVacia() const;
    size_t tamano() const;

private:
    vector<Carta> cartas;
    vector<Carta> descarte;
};

#endif