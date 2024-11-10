import heapq

def prim(graph, start=0):
    visited = set()
    min_heap = [(0, start, None)]  # (weight, current vertex, previous vertex)
    mst = []

    while len(visited) < len(graph):
        weight, current, prev = heapq.heappop(min_heap)
        if current not in visited:
            visited.add(current)
            if prev is not None:
                mst.append((prev, current, weight))

            for neighbor, edge_weight in graph[current].items():
                if neighbor not in visited:
                    heapq.heappush(min_heap, (edge_weight, neighbor, current))

    return mst