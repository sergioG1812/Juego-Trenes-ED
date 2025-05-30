#ifndef RUTA_H
#define RUTA_H
#include <string>
#include "Carta.h"
using namespace std;
struct Ruta {
    string origen;
    string destino;
    int longitud;
    Color colorRequerido;
    int jugadorId;
    
    Ruta(string orig, string dest, int lon, Color color);
};

#endif