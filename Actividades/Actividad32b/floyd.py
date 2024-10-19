"""
Este programa ejecuta el algoritmo de Flyod-Warshall
El programa debe leer un número n seguido de n x n valores enteros no negativos que 
representan una matriz de adyacencias de un grafo dirigido.

El primer número representa el número de nodos, los siguientes valores en la matriz, 
el valor en la posición i,j representan el peso del arco del nodo i al nodo j. 
Si no hay un arco entre el nodo i y el nodo j, el valor en la matriz debe ser -1.
"""
# Un valor muy grande 
INF = float('inf')

def floydWarshall(n, graph):
    # Iniciar la matriz de distancias
    distance = [[INF] * n for _ in range(n)] 

    # Copiar los valores del grafo a la matriz de distancias, reemplazando -1 por infinito
    for i in range(n):
        for j in range(n):
            if graph[i][j] == -1 and i != j:
                graph[i][j] = INF
            else:
                distance[i][j] = graph[i][j]
    
    # Algoritmo de Floyd-Warshal
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if distance[i][k] < INF and distance[k][j] < INF:
                    distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j])
    
    # Reemplazar infinitos por -1 en la salida
    for i in range(n):
        for j in range(n):
            if distance[i][j] == INF:
                distance[i][j] = -1
    
    return distance

# Leer la entrada
n = int(input("numero :"))
graph = [
    [0, 2, -1, 3,],
    [-1, 0, 1, 5],
    [2, 3, 0, -1],
    [3, -1, 4, 0],
]
"""
for _ in range(n):
    graph.append(list(map(int, input().split())))
"""

# Llamar al algoritmo
result = floydWarshall(n, graph)

for row in result:
    print(" ".join(map(str, row)))