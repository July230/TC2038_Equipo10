/*
Este programa ejecuta el problema de colorización de grafos

Para la solución de este problema se utiliza el algoritmo de Welsh-Powell, 
el cual consiste en ordenar los nodos de un grafo de acuerdo a su grado y 
posteriormente colorear los nodos de acuerdo a su orden, asignando el color más bajo 
posible que no haya sido asignado a sus vecinos.

Autores:
  - Ian Julián Estrada Castro A01352823
  - Maarten van 't Hoff A01764070
  - Diego Antonio García Padilla A01710777
*/

#include <iostream>
#include <vector>
#include <string.h>

#include "welsh_powell.h"

using namespace std;

int main()
{

    // ----- CASOS DE PRUEBA -----

    // TEST 1 (Grafo vacío)
    vector<vector<int>> graph1 = {};
    vector<int> result1 = welshPowell(graph1);
    // Resultado esperado: {}

    // TEST 2 (Grafo completo)
    vector<vector<int>> graph2 = 
    {
        {1, 2, 3},  // Nodo 0 conectado a 1, 2, 3
        {0, 2, 3},  // Nodo 1 conectado a 0, 2, 3
        {0, 1, 3},  // Nodo 2 conectado a 0, 1, 3
        {0, 1, 2}   // Nodo 3 conectado a 0, 1, 2
    };
    vector<int> result2 = welshPowell(graph2);
    // Resultado esperado: {0, 1, 2, 3} (4 colores)

    // TEST 3 (Grafo con 2 colores)
    vector<vector<int>> graph3 = 
    {
        {1, 3},  // Nodo 0 conectado a 1 y 3
        {0, 2},  // Nodo 1 conectado a 0 y 2
        {1, 3},  // Nodo 2 conectado a 1 y 3
        {0, 2}   // Nodo 3 conectado a 0 y 2
    };
    vector<int> result3 = welshPowell(graph3);
    // Resultado esperado: {0, 1, 0, 1} (alternando 2 colores)

    // TEST 4 (Grafo bipartito)
    vector<vector<int>> graph4 = 
    {
        {1, 2},      // Nodo 0 conectado a 1 y 2
        {0, 3, 4},   // Nodo 1 conectado a 0, 3 y 4
        {0, 5, 6},   // Nodo 2 conectado a 0, 5 y 6
        {1},         // Nodo 3 conectado a 1
        {1},         // Nodo 4 conectado a 1
        {2},         // Nodo 5 conectado a 2
        {2}          // Nodo 6 conectado a 2
    };
    vector<int> result4 = welshPowell(graph4);
    // Resultado esperado: {1, 0, 0, 1, 1, 1, 1} (2 colores)

    // ----- RESULTADOS -----

    // TEST 1
    cout << "----- TEST 1 -----" << endl;
    if (result1.size() == 0)
    {
        cout << "El grafo esta vacio" << endl;
    }

    // TEST 2
    cout << "----- TEST 2 -----" << endl;
    for (int i = 0; i < result2.size(); i++)
    {
        cout << "Vertice: " << i << ", Color asignado: " << result2[i] << endl;
    }

    // TEST 2
    cout << "----- TEST 3 -----" << endl;
    for (int i = 0; i < result3.size(); i++)
    {
        cout << "Vertice: " << i << ", Color asignado: " << result3[i] << endl;
    }

    // TEST 4
    cout << "----- TEST 4 -----" << endl;
    for (int i = 0; i < result4.size(); i++)
    {
        cout << "Vertice: " << i << ", Color asignado: " << result4[i] << endl;
    }

}