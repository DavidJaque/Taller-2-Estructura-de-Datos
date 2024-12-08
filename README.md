# Taller-2-Estructura-de-Datos

David Ignacio Jaque Torrejón / RUT: 20.996.192-K

Estructura de Datos - Taller 2 - Juego de Gato (Tic-Tac-Toe)

*Instrucciones para ejecutar el programa*

Ingresar en terminal:

g++ main.cpp tablero.cpp -o juego_gato

juego_gato


*Modo de juego:*

Al inicio del juego, se te pedirá que selecciones el modo de juego:
1: Jugador vs Jugador.
2: Jugador vs IA.


*Explicación del juego:*

El jugador puede ingresar las coordenadas de la fila y columna (0, 1, 2) donde desea colocar su ficha.
La IA tomará su turno automáticamente si el jugador selecciona el modo "Jugador vs IA".
El juego termina cuando un jugador gana, o si se llega a un empate.


*Explicación sobre el algoritmo utilizado*
Este programa implementa un juego de Gato (Tic-Tac-Toe) donde puedes jugar contra otro jugador o contra la IA. La IA utiliza el algoritmo Minimax para decidir su mejor movimiento.

*Algoritmo Minimax*
El algoritmo Minimax es una técnica utilizada en juegos de dos jugadores para tomar decisiones óptimas. El algoritmo evalúa todos los posibles movimientos y genera un "árbol de juego" donde cada nodo representa un estado del juego. Los jugadores alternan entre dos tipos de movimientos:

Maximizador (IA, 'O'): La IA busca maximizar su puntuación.
Minimizador (Jugador, 'X'): El jugador intenta minimizar la puntuación de la IA.

Minimax busca todos los movimientos posibles hasta que se alcanza un estado terminal (ganador o empate), y luego "retrocede" asignando un puntaje a cada estado del juego. El jugador maximizador elige el movimiento que maximiza su puntaje, mientras que el jugador minimizador elige el movimiento que minimiza la puntuación de su oponente.

*Poda Alfa-Beta*
La poda alfa-beta es una optimización del algoritmo Minimax que evita explorar ramas dl árbol de juego que no afectarán el resultado final. Funciona manteniendo dos valores, alfa y beta, donde:

Alfa: el valor máximo garantizado para el jugador maximizador
Beta: el valor mínimo garantizado para el jugador minimizador

Durante la exploración del árbol de juego, si se encuentra que una rama no puede producir un mejor resultado que uno ya encontrado, se poda (es decir, se omite) esa rama. Esto mejora significativamente el rendimiento sin afectar la calidad de la decisión tomada.


*Diagrama del árbol de juego para un caso simple*

Supongamos que los primeros tres movimientos del juego son los siguientes:

-> Jugador 'X' mueve en el centro del tablero
-> Jugador 'O' mueve en una esquina
-> Jugador 'X' mueve en otra esquina

El árbol de juego se vería de la siguiente manera, donde los nodos representan los posibles estados del juego después de cada movimiento, y las hojas del árbol representan los resultados finales (victoria, empate o derrota):


                  Inicio              
                    |                  
               X en el centro       
            /               \          
       O en esquina           X en esquina  
        /         \           /         \  
 X en esquina O en esquina  O en esquina X en esquina


Este árbol sigue creciendo con los movimientos alternados de los jugadores hasta que el juegop termina.

*Análisis de complejidad temporal*

*Complejidad del algoritmo Minimax sin poda alfa-beta:*
La complejidad del algoritmo Minimax para el juego de Gato es exponencial. Esto se debe a que en cada turno el algoritmo evalúa todos los posibles movimientos para cada jugador, y en un tablero 3x3 (como el del juego de Gato) hay un máximo de 9 movimientos posibles en el primer turno, 8 en el siguiente, y así sucesivamente.

La complejidad temporal sin poda alfa-beta es aproximadamente O(b^d), donde:

b: es el número de movimientos posibles por turno (en este caso, hasta 9 movimientos)
d: es la profundidad máxima del árbol de juego (en este caso, 9 movimientos)

Por lo tanto, el árbol tiene un tamaño de aproximadamente O(9^9) en el peor caso (aunque algunos movimientos se podan naturalmente debido a las reglas del juego)

*Complejidad después de aplicar la poda alfa-beta:*
Cuando se implementa la poda alfa-beta, la complejidad temporal se reduce considerablemente. En el mejor de los casos, la poda alfa-beta puede eliminar la necesidad de explorar un 50% o más de las ramas del árbol. Esto reduce la complejidad a O(b^(d/2)), donde:

b: es el número de movimientos posibles por turno
d: es la profundidad máxima del árbol de juego

Por lo tanto, si se implementa la poda alfa-beta, la complejidad temporal se reduce significativamente, lo que mejora la eficiencia del algoritmo.

*Conclusión*

El programa implementa un juego de Gato donde puedes jugar contra otro jugador o contra la IA. La IA utiliza el algoritmo Minimax para tomar decisiones óptimas, buscando maximizar su puntaje mientras minimiza el puntaje del jugador. La poda alfa-beta logra mejorar el rendimiento del algoritmo. El árbol de decisiones crece exponencialmente con la profundidad del juego, y la poda alfa-beta reduce significativamente esta complejidad.

