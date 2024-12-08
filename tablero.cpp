#include "tablero.hpp"
#include <iostream>
#include <limits>

Tablero::Tablero() 
{
    tablero = std::vector<std::vector<char>>(TAMANO, std::vector<char>(TAMANO, ' '));
}

void Tablero::mostrarTablero() const 
{
    std::cout << "  0   1   2\n";
    for (int i = 0; i < TAMANO; i++) {
        std::cout << i << " ";
        for (int j = 0; j < TAMANO; j++) {
            std::cout << tablero[i][j];
            if (j < TAMANO - 1) std::cout << " | ";
        }
        std::cout << "\n";
        if (i < TAMANO - 1) std::cout << " ---+---+---\n";
    }
}

bool Tablero::colocarFicha(int fila, int columna, char ficha) 
{
    if (esMovimientoValido(fila, columna)) {
        tablero[fila][columna] = ficha;
        return true;
    }
    return false;
}

bool Tablero::hayGanador(char& ganador) const
{
    for (int i = 0; i < TAMANO; i++) {
        if (tablero[i][0] != ' ' && tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2]) {
            ganador = tablero[i][0];
            return true;
        }
        if (tablero[0][i] != ' ' && tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i]) {
            ganador = tablero[0][i];
            return true;
        }
    }
    if (tablero[0][0] != ' ' && tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2]) {
        ganador = tablero[0][0];
        return true;
    }
    if (tablero[0][2] != ' ' && tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0]) {
        ganador = tablero[0][2];
        return true;
    }
    return false;
}

bool Tablero::esEmpate() const 
{
    for (int i = 0; i < TAMANO; i++) {
        for (int j = 0; j < TAMANO; j++) {
            if (tablero[i][j] == ' ') return false;
        }
    }
    return true;
}

bool Tablero::esMovimientoValido(int fila, int columna) const 
{
    return fila >= 0 && fila < TAMANO && columna >= 0 && columna < TAMANO && tablero[fila][columna] == ' ';
}

void Tablero::reiniciarTablero() 
{
    for (int i = 0; i < TAMANO; i++) {
        for (int j = 0; j < TAMANO; j++) {
            tablero[i][j] = ' ';
        }
    }
}

int Tablero::minimax(bool esMaximizador, int profundidad) 
{
    char ganador;
    if (hayGanador(ganador)) return (ganador == 'X') ? -10 : 10;
    if (esEmpate()) return 0;

    int mejorPuntaje = esMaximizador ? std::numeric_limits<int>::min() : std::numeric_limits<int>::max();
    for (int i = 0; i < TAMANO; i++) {
        for (int j = 0; j < TAMANO; j++) {
            if (esMovimientoValido(i, j)) {
                tablero[i][j] = esMaximizador ? 'O' : 'X';
                int puntaje = minimax(!esMaximizador, profundidad + 1);
                tablero[i][j] = ' ';
                mejorPuntaje = esMaximizador ? std::max(mejorPuntaje, puntaje) : std::min(mejorPuntaje, puntaje);
            }
        }
    }
    return mejorPuntaje;
}

std::pair<int, int> Tablero::mejorMovimiento(char fichaIA) 
{
    int mejorPuntaje = std::numeric_limits<int>::min();
    std::pair<int, int> movimiento = {-1, -1};
    for (int i = 0; i < TAMANO; i++) {
        for (int j = 0; j < TAMANO; j++) {
            if (esMovimientoValido(i, j)) {
                tablero[i][j] = fichaIA;
                int puntaje = minimax(false, 0);
                tablero[i][j] = ' ';
                if (puntaje > mejorPuntaje) {
                    mejorPuntaje = puntaje;
                    movimiento = {i, j};
                }
            }
        }
    }
    return movimiento;
}
