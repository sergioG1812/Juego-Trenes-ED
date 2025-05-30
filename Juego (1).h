#ifndef JUEGO_H
#define JUEGO_H
using namespace std;
#include <vector>
#include "Jugador.h"
#include "Baraja.h"
#include "Tablero.h"

class Juego {
public:
    Juego(int numJugadores);
    void iniciar();
    void mostrarEstado();
    void finalizarJuego();

private:
    void turnoJugador(int jugadorId);
    bool verificarFinJuego();
    int numJugadores;
    int jugadorActual;
    bool juegoTerminado;
    vector<Jugador> jugadores;
    Baraja baraja;
    Tablero tablero;
};

#endif
