"""
Este programa ejecuta el problema del viajero comerciante

Para la solución de este problema se utiliza el algoritmo de Dijkstra, 
pero con un enfoque avaro. El algoritmo busca encontrar la ruta mas corta 
que pase exactamente una vez por colonia, partiendo y regresando al inicio.

Autores:
  - Ian Julián Estrada Castro A01352823
*/
"""

import numpy as np


"""
 * dijkstraGreedy
 * @brief Funcion repara ejecutar el algoritmo de dijkstra con un enfoque avaro. Complejidad O(n^2)
 * n es el numero de vertices en el grafo
 * 
 * @param n numero de grafos
 * @param weight matriz de distancias entre nodos representado con un diccionario
 * 
 * @return Int
"""
def dijkstraGreedy(n, weight):
    visited = [False] * n 
    route = [0] 
    visited[0] = True 

    currentNode = 0
    totalDistance = 0

    # Mientras no se hayan visitado todas las colonias
    while len(route) < n:
        minDistance = float('inf')
        nextNode = -1
                
        for neighbor, distance in weight[currentNode].items():
            if not visited[neighbor] and distance < minDistance:
                minDistance = distance
                nextNode = neighbor

        # El siguiente nodo se marca como visitado y se actualiza la ruta
        visited[nextNode] = True
        route.append(nextNode)
        totalDistance += minDistance
        currentNode = nextNode

    # Regresar a la colonia de origen
    totalDistance += weight[currentNode][route[0]]
    route.append(route[0])

    return route, totalDistance
