#ifndef TABLERO_H
#define TABLERO_H
using namespace std;
#include <vector>
#include "Ruta.h"

class Tablero {
public:
    Tablero();
    void mostrar() const;
    const vector<Ruta>& getRutas() const;
    bool reclamarRuta(int indice, int jugadorId);
    bool rutaReclamada(int indice) const;
    bool todasRutasReclamadas() const;

private:
    vector<Ruta> rutas;
};

#endif