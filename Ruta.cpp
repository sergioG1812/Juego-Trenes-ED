#include "Ruta.h"

Ruta::Ruta(string orig, string dest, int lon, Color color) 
    : origen(orig), destino(dest), longitud(lon), 
      colorRequerido(color), jugadorId(-1) {}