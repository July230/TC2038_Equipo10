def readFile(filename):
    with open(filename, "r") as file:
        N = int(file.readline().strip())

        weights = [list(map(int, file.readline().strip().split())) for _ in range(N)]
        flows = [list(map(int, file.readline().strip().split())) for _ in range(N)]
        coords = [file.readline().strip() for _ in range(N+1)]

    weightGraph = initGraph(weights, N)
    flowGraph = initGraph(flows, N)

    return N, weightGraph, flowGraph, coords

def initGraph(adjacency, numNodes):
    graph = {}
    nodes = numNodes

    for i in range(nodes):
        graph[i] = {}
        for j in range(nodes):
            if adjacency[i][j] != -1 and (i != j or adjacency[i][j] != 0):
                graph[i][j] = adjacency[i][j]

    return graph