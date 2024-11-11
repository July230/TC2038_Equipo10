from readFile import readFile
from MinSpanTree import *
from FordFulkerson import *

filename = "./inputs/E5_Entrada_2.txt"
filename2 = "./inputs/E5_Entrada_3.txt"
N, weight, flow, coords = readFile(filename)
N2, weight2, flow2, coords2 = readFile(filename2)

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

# Algoritmo de Ford-Fulkerson
initialPathNode = 0
finalPathNode = max(flow2.keys()) # Ultimo nodo del grafo
maxFlow = fordFulkerson(flow2, initialPathNode, finalPathNode)
print("------------------------ Ford-Fulkerson caso 3 ------------------------")
print("Flujo máximo: ", maxFlow)