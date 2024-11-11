from readFile import readFile
from MinSpanTree import *
from FordFulkerson import *

filename = "./inputs/E5_Entrada_1.txt"
filename1 = "./inputs/E5_Entrada_2.txt"
filename2 = "./inputs/E5_Entrada_3.txt"
N, weight, flow, coords = readFile(filename)
N1, weight1, flow1, coords1 = readFile(filename1)
N2, weight2, flow2, coords2 = readFile(filename2)

print("------------------------ Caso 1 ------------------------")
print("N:", N)

print("Weight:")
for node in weight:
    print(f"Node {node}: {weight[node]}")

print("Flow:")
for node in flow:
    print(f"Node {node}: {flow[node]}")

print("Coords:")
for coord in coords:
    print(coord)

mst = prim(weight, start = 0)
print("Construcción óptima con pesos:")
for u, v, weight in mst:
    print(f"({u}, {v}): {weight}")

# Algoritmo de Ford-Fulkerson caso 1
initialPathNode = 0
finalPathNode = max(flow.keys()) # Ultimo nodo del grafo
maxFlow = fordFulkerson(flow, initialPathNode, finalPathNode)
print("------------------------ Ford-Fulkerson ------------------------")
print("Flujo máximo: ", maxFlow)

print("------------------------ Caso 2 ------------------------")

# Algoritmo de Ford-Fulkerson caso 2
initialPathNode = 0
finalPathNode = max(flow1.keys()) # Ultimo nodo del grafo
maxFlow1 = fordFulkerson(flow1, initialPathNode, finalPathNode)
print("------------------------ Ford-Fulkerson ------------------------")
print("Flujo máximo: ", maxFlow1)

print("------------------------ Caso 3 ------------------------")

# Algoritmo de Ford-Fulkerson caso 3
initialPathNode = 0
finalPathNode = max(flow2.keys()) # Ultimo nodo del grafo
maxFlow2 = fordFulkerson(flow2, initialPathNode, finalPathNode)
print("------------------------ Ford-Fulkerson ------------------------")
print("Flujo máximo: ", maxFlow2)