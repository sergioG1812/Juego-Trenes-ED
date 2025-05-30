#include "Tablero.h"
#include <iostream>
#include <iomanip>

using namespace std;

Tablero::Tablero() {
    rutas = {
        Ruta("A", "B", 4, Color::Rojo),
        Ruta("B", "C", 3, Color::Azul),
        Ruta("C", "D", 5, Color::Verde),
        Ruta("D", "E", 2, Color::Morado),
        Ruta("E", "F", 6, Color::Cafe),
        Ruta("F", "A", 4, Color::Naranja)
    };
}

void Tablero::mostrar() const {
    cout << "\n=== TABLERO ===" << endl;
    cout << left << setw(8) << "Origen" << setw(8) << "Destino"
         << setw(10) << "Longitud" << setw(15) << "Color" 
         << "Jugador" << endl;
    cout << "---------------------------------" << endl;
    
    for (size_t i = 0; i < rutas.size(); ++i) {
        const Ruta& r = rutas[i];
        cout << left << setw(8) << r.origen << setw(8) << r.destino
             << setw(10) << r.longitud 
             << setw(15) << Carta::colorACadena(r.colorRequerido);
        
        if (r.jugadorId == -1) {
            cout << "Disponible";
        } else {
            cout << "Jugador " << r.jugadorId;
        }
        cout << endl;
    }
    cout << endl;
}

const vector<Ruta>& Tablero::getRutas() const {
    return rutas;
}

bool Tablero::reclamarRuta(int indice, int jugadorId) {
    if (indice < 0 || indice >= static_cast<int>(rutas.size())) return false;
    if (rutas[indice].jugadorId != -1) return false;
    
    rutas[indice].jugadorId = jugadorId;
    return true;
}

bool Tablero::rutaReclamada(int indice) const {
    return rutas[indice].jugadorId != -1;
}

bool Tablero::todasRutasReclamadas() const {
    for (const auto& ruta : rutas) {
        if (ruta.jugadorId == -1) {
            return false;
        }
    }
    return true;
}