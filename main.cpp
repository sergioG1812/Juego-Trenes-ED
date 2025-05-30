#include "Juego.h"
#include <iostream>

using namespace std;

int main() {
    cout << "      JUEGO DE TRENES      " << endl;
    cout << "Instrucciones:\n"
         << "- En cada turno puedes:\n"
         << "  1. Robar 2 cartas\n"
         << "  2. Reclamar una ruta (usando cartas del color requerido)\n"
         << "- El juego termina cuando un jugador tiene menos de 5 vagones\n"
         << "- Puntuacion:\n"
         << "  2 vagones: 1 punto\n"
         << "  3 vagones: 2 puntos\n"
         << "  4 vagones: 4 puntos\n"
         << "  5 vagones: 6 puntos\n"
         << "  6 vagones: 9 puntos\n" << endl;

    int numJugadores;
    do {
        cout << "Numero de jugadores (2-4): ";
        cin >> numJugadores;
    } while (numJugadores < 2 || numJugadores > 4);

    Juego juego(numJugadores);
    juego.iniciar();

    return 0;
}