/*
Este programa ejecuta el problema de la mochila (knapsack problem)

La entrada al programa es un número N que representa el número de elementos posibles disponibles,
seguido de N enteros que representan el valor de cada uno de esos elementos,
seguido de N enteros que representan los pesos asociados a cada elemento.
por último, un entero W, que representa el peso máximo o capacidad de la mochila.
La salida del programa debe ser la ganancia (o beneficio) óptimo.

Autores Ian Julián Estrada Castro A01352823,  Maarten van 't Hoff A01764070 y Diego Antonio García Padilla A01710777
*/

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

// knapSack ejecuta un algoritmo de programación dinámica
// Se construye una matriz donde las filas son el objeto disponible
// Las columnas son la capacidad de la mochila
// Complejidad O(n^2)
int knapSack(int N, vector<int>& values, vector<int>& weights, int W){
    // Crear una matriz de Programacion dinamica (N+1) x (W+1)
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
    // dp es DynamicPrograming

    // Llenar la matriz de programacion dinamica
    for(int i = 1; i <= N; i++){
        for(int w = 1; w <= W; w++){
            if(weights[i - 1] <= w){
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    // Matriz generada
    cout << "Matriz generada" << endl;
    for(int i = 0; i <= N; i++){
        for(int w = 0; w <= W; w++){
            cout << dp[i][w] << " ";
        }
        cout << endl;
    }

    // El beneficio optimo esta en dinamicPrograming[N][W]
    return dp[N][W];
}