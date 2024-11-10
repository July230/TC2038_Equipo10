from readFile import readFile
from MinSpanTree import *

filename = "./inputs/E5_Entrada_2.txt"
N, weight, flow, coords = readFile(filename)

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