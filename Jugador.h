#ifndef JUGADOR_H
#define JUGADOR_H
using namespace std;
#include <vector>
#include "Carta.h"

class Jugador {
public:
    Jugador(int id, int vagonesIniciales);
    
    void robarCarta(Carta carta);
    bool intentarReclamarRuta(int costo, Color color);
    void reclamarRuta(int longitud);
    int calcularPuntuacion() const;
    std::vector<Carta> descartarCartas(Color color, int cantidad);
    
    int getId() const;
    int getVagones() const;
    const vector<Carta>& getCartas() const;
    int getCartasColor(Color color) const;
    
private:
    int id;
    int vagones;
    vector<Carta> cartas;
    vector<int> rutasReclamadas;
};

#endif