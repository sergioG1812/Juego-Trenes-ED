#include "Baraja.h"
#include <algorithm>
#include <random>
#include <ctime>
#include <stdexcept>

using namespace std;

Baraja::Baraja() {
    inicializar();
}

void Baraja::inicializar() {
    cartas.clear();
    descarte.clear();
    
    for (int i = 0; i < 12; ++i) {
        cartas.push_back(Carta(Color::Rojo));
        cartas.push_back(Carta(Color::Azul));
        cartas.push_back(Carta(Color::Verde));
        cartas.push_back(Carta(Color::Morado));
        cartas.push_back(Carta(Color::Cafe));
        cartas.push_back(Carta(Color::Naranja));
    }
    barajar();
}

void Baraja::barajar() {
    srand(static_cast<unsigned>(time(0)));
    random_shuffle(cartas.begin(), cartas.end());
}

Carta Baraja::robarCarta() {
    if (cartas.empty()) {
        reponerDesdeDescarte();
        if (cartas.empty()) {
            throw runtime_error("No hay cartas disponibles");
        }
    }
    
    Carta carta = cartas.back();
    cartas.pop_back();
    return carta;
}

void Baraja::reponerDesdeDescarte() {
    cartas = descarte;
    descarte.clear();
    barajar();
}

void Baraja::descartar(const vector<Carta>& cartasDescartadas) {
    for (const auto& carta : cartasDescartadas) {
        descarte.push_back(carta);
    }
}

bool Baraja::estaVacia() const {
    return cartas.empty() && descarte.empty();
}

size_t Baraja::tamano() const {
    return cartas.size() + descarte.size();
}