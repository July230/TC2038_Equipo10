from readFile import readFile
from MinSpanTree import *
from FordFulkerson import *
from DijkstraGreedy import *

filename = "./inputs/E5_Entrada_1.txt"
filename1 = "./inputs/E5_Entrada_2.txt"
filename2 = "./inputs/E5_Entrada_3.txt"
N, weights, flow, coords = readFile(filename)
N1, weights1, flow1, coords1 = readFile(filename1)
N2, weights2, flow2, coords2 = readFile(filename2)

print("------------------------ Caso 1 ------------------------")
print("N:", N)

print("Weights:")
for node in weights:
    print(f"Node {node}: {weights[node]}")

print("Flow:")
for node in flow:
    print(f"Node {node}: {flow[node]}")

print("Coords:")
for coord in coords:
    print(coord)

mst = prim(weights, start = 0)
print("-------------------------- MST con Prim -------------------------")
for u, v, weight in mst:
    print(f"({u}, {v}): {weight}")

print("------------------------ Dijkstra Greedy ------------------------")
route, totalDistance = dijkstraGreedy(N, weights)
routeLetters = [chr(ord('A') + i) for i in route]
print("Ruta:", ' -> '.join(routeLetters))
print("Distancia total: ", totalDistance)

# Algoritmo de Ford-Fulkerson caso 1
initialPathNode = 0
finalPathNode = max(flow.keys()) # Ultimo nodo del grafo
maxFlow = fordFulkerson(flow, initialPathNode, finalPathNode)
print("------------------------ Ford-Fulkerson ------------------------")
print("Flujo máximo: ", maxFlow)

print("------------------------ Caso 2 ------------------------")
print("N:", N1)

print("Weights:")
for node in weights1:
    print(f"Node {node}: {weights1[node]}")

print("Flow:")
for node in flow1:
    print(f"Node {node}: {flow1[node]}")

print("Coords:")
for coord in coords1:
    print(coord)

mst = prim(weights1, start = 0)
print("-------------------------- MST con Prim -------------------------")
for u, v, weight in mst:
    print(f"({u}, {v}): {weight}")

print("------------------------ Dijkstra Greedy ------------------------")
route, totalDistance = dijkstraGreedy(N1, weights1)
routeLetters = [chr(ord('A') + i) for i in route]
print("Ruta:", ' -> '.join(routeLetters))
print("Distancia total: ", totalDistance)

# Algoritmo de Ford-Fulkerson caso 2
initialPathNode = 0
finalPathNode = max(flow1.keys()) # Ultimo nodo del grafo
maxFlow1 = fordFulkerson(flow1, initialPathNode, finalPathNode)
print("------------------------ Ford-Fulkerson ------------------------")
print("Flujo máximo: ", maxFlow1)

print("------------------------ Caso 3 ------------------------")
print("N:", N2)

print("Weights:")
for node in weights2:
    print(f"Node {node}: {weights2[node]}")

print("Flow:")
for node in flow2:
    print(f"Node {node}: {flow2[node]}")

print("Coords:")
for coord in coords2:
    print(coord)

mst = prim(weights2, start = 0)
print("-------------------------- MST con Prim -------------------------")
for u, v, weight in mst:
    print(f"({u}, {v}): {weight}")

print("------------------------ Dijkstra Greedy ------------------------")
route, totalDistance = dijkstraGreedy(N2, weights2)
routeLetters = [chr(ord('A') + i) for i in route]
print("Ruta:", ' -> '.join(routeLetters))
print("Distancia total: ", totalDistance)

# Algoritmo de Ford-Fulkerson caso 3
initialPathNode = 0
finalPathNode = max(flow2.keys()) # Ultimo nodo del grafo
maxFlow2 = fordFulkerson(flow2, initialPathNode, finalPathNode)
print("------------------------ Ford-Fulkerson ------------------------")
print("Flujo máximo: ", maxFlow2)