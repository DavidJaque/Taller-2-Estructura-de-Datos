#include <iostream>
#include "tablero.hpp"

int main() {
    Tablero tablero;
    char ganador = ' ';
    char jugadorActual = 'X';
    int modo;

    std::cout << "### JUEGO # GATO ###\n";
    std::cout << "Selecciona el modo de juego:\n";
    std::cout << "1 -> Jugador vs Jugador\n";
    std::cout << "2 -> Jugador vs IA\n";
    std::cin >> modo;

    while (true) {
        tablero.mostrarTablero();

        if (modo == 2 && jugadorActual == 'O') {
            std::cout << "Turno de la IA...\n";
            auto movimiento = tablero.mejorMovimiento('O');
            int fila = movimiento.first;
            int columna = movimiento.second;
            tablero.colocarFicha(fila, columna, 'O');
        } else {
            int fila, columna;
            std::cout << "Turno del jugador " << jugadorActual << ". Ingresa fila y columna: ";
            std::cin >> fila >> columna;

            if (!tablero.colocarFicha(fila, columna, jugadorActual)) {
                std::cout << "Eror: moviemiento invalido... Intenta denuevo\n";
                continue;
            }
        }

        if (tablero.hayGanador(ganador)) {
            tablero.mostrarTablero();
            std::cout << "Jugador " << ganador << " es el ganador!\n";
            break;
        } else if (tablero.esEmpate()) {
            tablero.mostrarTablero();
            std::cout << "Es un empate!\n";
            break;
        }

        jugadorActual = (jugadorActual == 'X') ? 'O' : 'X';
    }

    return 0;
}
