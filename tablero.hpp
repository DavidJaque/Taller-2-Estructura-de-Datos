#ifndef TABLERO_HPP
#define TABLERO_HPP

#include <vector>
#include <string>
#include <limits> 

class Tablero {
private:
    std::vector<std::vector<char>> tablero;
    const int TAMANO = 3;   // tamaño del tablero

public:
    Tablero();

    void mostrarTablero() const;
    bool colocarFicha(int fila, int columna, char ficha);
    bool hayGanador(char& ganador) const;
    bool esEmpate() const;
    bool esMovimientoValido(int fila, int columna) const;
    void reiniciarTablero();

    // minimax
    int minimax(bool esMaximizador, int profundidad);
    std::pair<int, int> mejorMovimiento(char fichaIA);
};

#endif
