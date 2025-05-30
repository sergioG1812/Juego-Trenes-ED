#include "Juego.h"
#include <iostream>
#include <limits>

using namespace std;

Juego::Juego(int numJugadores) 
    : numJugadores(numJugadores), jugadorActual(0), juegoTerminado(false) {
    for (int i = 0; i < numJugadores; ++i) {
        jugadores.push_back(Jugador(i, 18));
    }
}

void Juego::iniciar() {
    while (!juegoTerminado) {
        turnoJugador(jugadorActual);
        jugadorActual = (jugadorActual + 1) % numJugadores;
        juegoTerminado = verificarFinJuego();
    }
    finalizarJuego();
}

void Juego::turnoJugador(int jugadorId) {
    cout << "\n= Turno del Jugador " << jugadorId << " =" << endl;
    mostrarEstado();

    Jugador& jugador = jugadores[jugadorId];
    bool accionCompletada = false;
    
    while (!accionCompletada) {
        int opcion;
        cout << "Opciones:\n1. Robar cartas\n2. Realizar trayecto\nEleccion: ";
        cin >> opcion;

        if (opcion == 1) {
            int cartasRobadas = 0;
            try {
                Carta c1 = baraja.robarCarta();
                jugador.robarCarta(c1);
                cartasRobadas++;
            } catch (const exception& e) {
                cout << "Error al robar primera carta: " << e.what() << endl;
            }
            try {
                Carta c2 = baraja.robarCarta();
                jugador.robarCarta(c2);
                cartasRobadas++;
            } catch (const exception& e) {
                cout << "Error al robar segunda carta: " << e.what() << endl;
            }
            cout << "Robaste " << cartasRobadas << " cartas" << endl;
            accionCompletada = true;
        } 
        else if (opcion == 2) {
            if (tablero.todasRutasReclamadas()) {
                cout << "Todas las rutas han sido reclamadas! No puedes construir mas.\n";
                continue;
            }
            
            tablero.mostrar();
            int rutaIndex;
            cout << "Selecciona ruta (0-" << tablero.getRutas().size()-1 << ") o -1 para cancelar: ";
            cin >> rutaIndex;
            
            if (rutaIndex == -1) {
                continue;
            }
            
            if (rutaIndex < 0 || rutaIndex >= static_cast<int>(tablero.getRutas().size())) {
                cout << "Indice de ruta inválido" << endl;
                continue;
            }
            
            const Ruta& ruta = tablero.getRutas()[rutaIndex];
            
            if (tablero.rutaReclamada(rutaIndex)) {
                cout << "Esta ruta ya ha sido reclamada" << endl;
                continue;
            }
            
            if (jugador.getVagones() < ruta.longitud) {
                cout << "No tienes suficientes vagones para esta ruta" << endl;
                continue;
            }
            
            if (jugador.getCartasColor(ruta.colorRequerido) < ruta.longitud) {
                cout << "No tienes suficientes cartas de color " 
                     << Carta::colorACadena(ruta.colorRequerido) << "!" << endl;
                continue;
            }
            
            vector<Carta> cartasUsadas = jugador.descartarCartas(ruta.colorRequerido, ruta.longitud);
            jugador.reclamarRuta(ruta.longitud);
            tablero.reclamarRuta(rutaIndex, jugadorId);
            baraja.descartar(cartasUsadas);
            cout << "Ruta reclamada con éxito" << endl;
            accionCompletada = true;
        }
        else {
            cout << "Opción inválida. Intenta de nuevo." << endl;
        }
    }
}

void Juego::mostrarEstado() {
    cout << "\n--- Estado Actual ---" << endl;
    for (const auto& jugador : jugadores) {
        cout << "Jugador " << jugador.getId() 
             << " | Vagones: " << jugador.getVagones()
             << " | Puntos: " << jugador.calcularPuntuacion() << endl;
        
        cout << "  Cartas: ";
        cout << "Rojo: " << jugador.getCartasColor(Color::Rojo) << " ";
        cout << "Azul: " << jugador.getCartasColor(Color::Azul) << " ";
        cout << "Verde: " << jugador.getCartasColor(Color::Verde) << " ";
        cout << "Morado: " << jugador.getCartasColor(Color::Morado) << " ";
        cout << "Cafe: " << jugador.getCartasColor(Color::Cafe) << " ";
        cout << "Naranja: " << jugador.getCartasColor(Color::Naranja) << endl;
    }
    cout << "Cartas restantes: " << baraja.tamano() << endl;
}

bool Juego::verificarFinJuego() {
    // Condición 1: Alguien tiene menos de 5 vagones
    for (const auto& jugador : jugadores) {
        if (jugador.getVagones() < 5) {
            cout << "\n= FINAL DEL JUEGO =" << endl;
            cout << "Jugador " << jugador.getId() << " tiene menos de 5 vagones" << endl;
            return true;
        }
    }
    
    // Condición 2: Todas las rutas han sido reclamadas
    if (tablero.todasRutasReclamadas()) {
        cout << "\n=== FINAL DEL JUEGO ===" << endl;
        cout << "Todas las rutas han sido reclamadas" << endl;
        return true;
    }
    
    return false;
}

void Juego::finalizarJuego() {
    cout << "\n=== PUNTUACIONES FINALES ===" << endl;
    int maxPuntos = -1;
    int ganador = -1;
    
    for (const auto& jugador : jugadores) {
        int puntos = jugador.calcularPuntuacion();
        cout << "Jugador " << jugador.getId() << ": " << puntos << " puntos" << endl;
        
        if (puntos > maxPuntos) {
            maxPuntos = puntos;
            ganador = jugador.getId();
        }
    }
    cout << "\nJugador " << ganador << " gana con " << maxPuntos << " puntos" << endl;
}