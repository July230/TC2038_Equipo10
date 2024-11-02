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

using namespace std;

/**
 * @brief Esta función recibe un grafo y regresa un vector con los colores asignados a cada nodo
 * 
 * @param graph Grafo en forma de lista de adyacencia
 * 
 * @return Vector con los colores asignados a cada nodo
 */
vector<int> welshPowell(vector<vector<int>> graph)
{
    // Se obtiene el número de nodos
    int n = graph.size();

    // Si el grafo está vacío, se regresa un vector vacío
    if (n == 0)
    {
        return {};
    }

    // Se crea un vector para almacenar los grados de cada nodo
    vector<int> degrees(n);

    // Se calcula el grado de cada nodo
    for (int i = 0; i < n; i++)
    {
        // Dado a que el grafo es representado por una lista de adyacencia, 
        // el grado de un nodo es el número de vecinos que tiene
        degrees[i] = graph[i].size();
    }

    // Se crea un vector para almacenar los colores asignados a cada nodo
    vector<int> colors(n, -1);

    // Se crea un vector para almacenar los nodos ordenados de acuerdo a su grado
    vector<int> nodes_sorted(n);

    // Se inicializa el vector de nodos ordenados
    for (int i = 0; i < n; i++)
    {
        nodes_sorted[i] = i;
    }

    // Se ordenan los nodos de acuerdo a su grado 
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // Si el grado del nodo i es menor al grado del nodo j, se intercambian
            if (degrees[nodes_sorted[i]] < degrees[nodes_sorted[j]])
            {
                swap(nodes_sorted[i], nodes_sorted[j]);
            }
        }
    }

    // Se crea un vector para almacenar los colores que ya han sido asignados
    vector<bool> used_colors(n, false);

    // Se asignan los colores a los nodos
    for (int i = 0; i < n; i++)
    {
        // Se obtiene el nodo
        int node = nodes_sorted[i];

        // Se crea un vector para almacenar los colores que ya han sido asignados a los vecinos
        vector<bool> used_colors_neighbors(n, false);

        // Se recorren los vecinos del nodo
        for (int neighbor : graph[node])
        {
            // Si el vecino ya tiene un color asignado, se marca en el vector de colores usados
            if (colors[neighbor] != -1)
            {
                used_colors_neighbors[colors[neighbor]] = true;
            }
        }

        // Se asigna el color más bajo posible que no haya sido asignado a los vecinos
        for (int j = 0; j < n; j++)
        {
            if (!used_colors_neighbors[j])
            {
                colors[node] = j;
                used_colors[j] = true;
                break;
            }
        }

    }

    // Se regresa el vector con los colores asignados a cada nodo
    return colors;
}

