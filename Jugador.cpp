#include "Jugador.h"
using namespace std;

Jugador::Jugador(int id, int vagonesIniciales) : id(id), vagones(vagonesIniciales) {}

void Jugador::robarCarta(Carta carta) {
    cartas.push_back(carta);
}

bool Jugador::intentarReclamarRuta(int costo, Color color) {
    if (vagones < costo) return false;
    
    int contador = 0;
    for (const auto& carta : cartas) {
        if (carta.getColor() == color) {
            contador++;
        }
    }
    return contador >= costo;
}

void Jugador::reclamarRuta(int longitud) {
    rutasReclamadas.push_back(longitud);
    vagones -= longitud;
}

int Jugador::calcularPuntuacion() const {
    int puntos = 0;
    for (int longitud : rutasReclamadas) {
        switch (longitud) {
            case 2: puntos += 1; break;
            case 3: puntos += 2; break;
            case 4: puntos += 4; break;
            case 5: puntos += 6; break;
            case 6: puntos += 9; break;
        }
    }
    return puntos;
}

int Jugador::getId() const { return id; }
int Jugador::getVagones() const { return vagones; }
const vector<Carta>& Jugador::getCartas() const { return cartas; }

int Jugador::getCartasColor(Color color) const {
    int contador = 0;
    for (const auto& carta : cartas) {
        if (carta.getColor() == color) {
            contador++;
        }
    }
    return contador;
}

vector<Carta> Jugador::descartarCartas(Color color, int cantidad) {
    vector<Carta> descartadas;
    int contador = 0;
    auto it = cartas.begin();
    
    while (contador < cantidad && it != cartas.end()) {
        if (it->getColor() == color) {
            descartadas.push_back(*it);
            it = cartas.erase(it);
            contador++;
        } else {
            ++it;
        }
    }
    return descartadas;
}