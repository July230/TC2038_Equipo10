from dijkstra import *
from floyd import *

# Valor de n
n = int(input("numero : "))

# Matriz de adyacencia
graph = [
    [0, 2, -1, 3,],
    [-1, 0, 1, 5],
    [2, 3, 0, -1],
    [3, -1, 4, 0],
]

# Dijkstra
print("\n----- DIJKSTRA -----\n")

# Inicializar grafo como diccionario para Dijkstra
graph_dijkstra = initGraph(graph, n)

# Llamar al algoritmo de Dijkstra
for node in graph_dijkstra:
    print(f"Node {node}: {graph[node]}")
    distanceList = dijkstra(graph_dijkstra, node)
    for dest, dist in distanceList.items():
        if dest != node:
            print(f"node {node} to node {dest}: {dist}")

# Floyd-Warshall
print("\n----- FLOYD-WARSHALL -----\n")

# Llamar al algoritmo de Floyd-Warshall
result = floydWarshall(n, graph)

for row in result:
    print(" ".join(map(str, row)))