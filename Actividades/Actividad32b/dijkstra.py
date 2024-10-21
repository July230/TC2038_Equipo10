"""
Maarten Roelof van 't Hoff - A01764070
Algoritmo de Dijkstra - Actividad 32b
Este programa ejecuta el algoritmo de Dijkstra a mano de una matriz de adyacencia.
Complejidad O(E log V), donde E es el número de aristas y V el número de vértices en el grafo.
Toma una lista/matriz de adyacencia con los pesos entre nodos
La matriz se convierte a un diccionario para facilitar en el proceso de Dijkstra
Nodos con -1 en la matriz no se agregan al diccionario por no tener arco
"""

import heapq # usamos el heap para ya ordenar la fila mientras que corre el Dijkstra

## Inicializar al grafo como diccionario para leer en "Dijkstra"
def initGraph(adjacency, numNodes):
    graph = {}
    nodes = numNodes # inicializa la cantidad de nodos que tenemos con el valor numNodes

    for i in range(nodes):
        graph[i] = {}
        for j in range(nodes): # Para cada nodo en la lista pasamos todos los arcos
            if adjacency[i][j] != -1 and (i != j or adjacency[i][j] != 0): # Logica para ver si hay arco o si el nodo es 0 en su mismo
                graph[i][j] = adjacency[i][j]

    return graph

def dijkstra(graph, source):
    distances = {node : float('infinity') for node in graph} # Distancia minima se incializa como infinito
    distances[source] = 0

    queue = [(0, source)] # Empieza la fila con el primer nodo (source) y su distancia minima (0)

    while queue:
        currDist, currNode = heapq.heappop(queue) # Tomar el primer elemento de la fila heap

        if currDist > distances[currNode]: # Si la distancia es mayor que la distancia que ya tenemos al nodo, no cambiamos el valor
            continue

        for neighbor, weight in graph[currNode].items():
            distance = currDist + weight

            if distance < distances[neighbor]:
                distances[neighbor] = distance # Cambiamos la distancia a uno de menor distancia
                heapq.heappush(queue, (distance, neighbor)) # En el caso de cambiar la distancia, agregamos el vecino al heap

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