"""
Este programa ejecuta la creación del "minimum spanning tree" por uso del algoritmo Prim.
El algoritmo busca el árbol del grafo con el peso total minimo. Esto se aplica para la problema 1
de la actividad integradora para buscar la construcción más optima de los cables opticas.

Autores:
  - Maarten Roelof van 't Hoff A01764070
*/
"""
import heapq

"""
 * prim
 * @brief Función busca el árbol de un grafo con el menor peso total
 * 
 * @param grafo de pesos en cual queremos encontrar el mst
 * @param start nodo en donde empezamos el árbol
 * 
 * @return msst (lista de arcos entre nodos con posos)
"""
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