from readFile import readFile

filename = "./inputs/E5_Entrada_1.txt"
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