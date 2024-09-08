/*
Este programa utiliza la técnica de backtracking
El programa recibe dos números enteros M y N, seguido de M líneas de N valores booleanos(0|1) separados por un espacio, 
por la entrada estándar que representan el laberinto. Un 1 representa una casilla en la que es posible moverse, un 0 es una casilla por la que NO se puede pasar. 
El origen o casilla de inicio es siempre la casilla (0,0) y la salida o meta es siempre la casilla (M-1, N-1).

La salida del programa es una matriz de valores booleanos (0|1) que representan el camino para salir del laberinto. 

Autores: Maarten van 't Hoff A01764070 y Ian Julian Estrada Castro A01352823
Fecha: 08/09/2024

*/

#include <iostream>
#include <vector>
#include <ctime>
#include <stdlib.h>

using namespace std;

// isValid verifica si una posicion es valida
// Debe estar dentro de los limites de la matriz, ser accesible y no visitada
// Complejidad temporal de O(1), complejidad espacial de O(1)
bool isValid(vector<vector<int>>& maze, int x, int y, vector<vector<int>>& solution, int M, int N){
    return (x >= 0 && x < M && y >= 0 && y < N && maze[x][y] == 1 && solution[x][y] == 0);
}

// solveMaze es una solucion recursiva para recorrer el laberinto
// Complejidad temporal de O(4^(M*N)), M filas y N columnas
// Complejidad espacial de O(M*N)
bool solveMaze(vector<vector<int>>& maze, int x, int y, vector<vector<int>>& solution, int M, int N){
    // El caso base es si se ha llegado a la salida (M-1, N-1)
    if(x == M - 1 && y == N - 1){
        solution[x][y] = 1;
        return true;
    }

    if(isValid(maze, x, y, solution, M, N)){
        solution[x][y] = 1; // La casilla actual es parte del camino

        // Moverse abajo
        if(solveMaze(maze, x, y - 1, solution, M, N)){
            return true;
        }
        // Meverse a la derecha
        if(solveMaze(maze, x + 1, y, solution, M, N)){
            return true;
        }
        // Moverse arriba
        if(solveMaze(maze, x, y + 1, solution, M, N)){
            return true;
        }
        // Moverse a la izquierda
        if(solveMaze(maze, x - 1, y, solution, M, N)){
            return true;
        }

        // Si ninguna de las soluciones funciona, se desmarca y se devuelve false, el camino no es correcto
        solution[x][y] = 0;
        return false;
    }
    return false;
}

// maze inicia la solucion del laberinto
// Inicia la matriz de solucion con complejidad O(M*N) y llama a solveMaze
vector<vector<int>> maze(int M, int N, vector<vector<int>>& maze){
    vector<vector<int>> solution(M, vector<int>(N, 0));

    if(solveMaze(maze, 0, 0, solution, M, N)){
        return solution;
    } else {
        return {}; // Devolver vacio si no hay solucion
    }
}

void printMatrix(const vector<vector<int>>& matrix, int M, int N){
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int M = 4;
    int N = 4;
    vector<vector<int>> maze1 = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    vector<vector<int>> solution = maze(M, N, maze1);

    if(!solution.empty()){
        cout << "Solucion" << endl;
        printMatrix(solution, M, N);
    } else {
        cout << "No hay solucion posible" << endl;
    }

    int M1 = 6;
    int N1 = 6;
    vector<vector<int>> maze2 = {
        {1, 1, 1, 1, 0, 1},
        {1, 1, 0, 1, 1, 1},
        {1, 0, 0, 1, 0, 1},
        {1, 1, 0, 1, 0, 1},
        {0, 1, 0, 1, 1, 1},
        {1, 1, 1, 1, 0, 1},
    };

    vector<vector<int>> solution1 = maze(M1, N1, maze2);

    if(!solution1.empty()){
        cout << "Solucion 2" << endl;
        printMatrix(solution1, M1, N1);
    } else {
        cout << "No hay solucion posible" << endl;
    }

    int M2 = 4;
    int N2 = 4;
    vector<vector<int>> maze3 = {
        {1, 0, 0, 0},
        {1, 1, 1, 0},
        {0, 1, 1, 1},
        {1, 0, 0, 1}
    };

    vector<vector<int>> solution2 = maze(M2, N2, maze3);

    if(!solution2.empty()){
        cout << "Solucion 3" << endl;
        printMatrix(solution2, M2, N2);
    } else {
        cout << "No hay solucion posible" << endl;
    }

    int M3 = 7;
    int N3 = 9;
    vector<vector<int>> maze4 = {
        {1, 1, 0, 1, 1, 1, 1, 1, 0},
        {0, 1, 1, 1, 0, 0, 0, 1, 1},
        {1, 1, 0, 1, 1, 1, 1, 1, 0},
        {1, 0, 0, 0, 1, 1, 0, 1, 1},
        {1, 1, 0, 1, 1, 0, 0, 0, 1},
        {0, 1, 0, 1, 0, 1, 0, 0, 1},
        {1, 1, 1, 1, 0, 1, 1, 0, 1},
    };

    vector<vector<int>> solution3 = maze(M3, N3, maze4);

    if(!solution3.empty()){
        cout << "Solucion 4" << endl;
        printMatrix(solution3, M3, N3);
    } else {
        cout << "No hay solucion posible" << endl;
    }

    return 0;
}