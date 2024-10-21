"""
Maarten Roelof van 't Hoff - A01764070
Algoritmo de Dijkstra - Actividad 32b
Este programa ejecuta el algoritmo de Dijkstra a mano de una matriz de adyacencia.
"""

import heapq
import math

## Inicializar al grafo como diccionario para leer en "Dijkstra"
def initGraph(adjacency):
    graph = {}
    nodes = len(adjacency)

    for i in range(nodes):
        graph[i] = {}
        for j in range(nodes):
            if adjacency[i][j] != -1 and adjacency[i][j] != 0:
                graph[i][j] = adjacency[i][j]

    return graph

def dijkstra(graph, source):
    distances = {node : float('infinity') for node in graph}
    distances[source] = 0

    queue = [(0, source)]

    while queue:
        currDist, currNode = heapq.heappop(queue)

        if currDist > distances[currNode]:
            continue

        for neighbor, weight in graph[currNode].items():
            distance = currDist + weight

            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(queue, (distance, neighbor))

    return distances

if __name__ == "__main__":
    # Matriz de adyacencia
    graph = [
        [0, 2, -1, 3,],
        [-1, 0, 1, 5],
        [2, 3, 0, -1],
        [3, -1, 4, 0],
    ]

    # Inicializar grafo
    graph = initGraph(graph)

    # Llamar al algoritmo de Dijkstra
    for node in graph:
        print(f"Node {node}: {graph[node]}")
        distanceList = dijkstra(graph, node)
        for dest, dist in distanceList.items():
            if dest != node:
                print(f"node {node} to node {dest}: {dist}")