"""
Este programa ejecuta el problema de flujo máximo de grafos

Para la solución de este problema se utiliza el algoritmo de Ford-Fulkerson, 
el cual consiste en calcular la mayor cantidad de "flujo" que puede pasar de un nodo 
origen a un nodo de destino en una red de caminos, considerando de cada camino
tiene restricciones en capacidad

Autores:
  - Ian Julián Estrada Castro A01352823
*/
"""


"""
 * dfs
 * @brief Funcion residual para realizar DFS y encontrar un camino que aumenta.
 * f es el flujo maximo y E es el numero de aristas (uniones) en una red 
 * 
 * @param residualGraph grafo con capacidad residual en forma de lista de adyacencia representada como diccionario
 * @param initialNode el nodo inicial del flujo
 * @param finalNode el nodo final del flujo
 * @param path diccionario para guardar los pasos del camino desde el inicio al final, se reconstruye el camino encontrado
 * @param visited diccionario que guarda nodos visitados en el camino
 * 
 * @return Bool
"""
def dfs(residualGraph, initialPathNode, finalPathNode, path, visited):
    visited[initialPathNode] = True
    # El nodo actual (fuente) es el mismo que el final, se encontro un camino 
    if initialPathNode == finalPathNode:
        return True
    
    for node, capacity in residualGraph[initialPathNode].items():
        if not visited[node] and capacity > 0: # Nodo sin visitar y con capacidad
            path[node] = initialPathNode
            # Continua la busqueda
            if dfs(residualGraph, node, finalPathNode, path, visited):
                return True 
            
    # Caso base: No se encontro un camino que aumenta al final del ciclo
    return False

"""
 * dfs
 * @brief Funcion residual para realizar DFS y encontrar un camino que aumenta. Complejidad O(fE)
 * f es el flujo maximo y E es el numero de aristas (uniones) en una red 
 * 
 * @param graph grafo en forma de lista de adyacencia representada como diccionario
 * @param initialNode el nodo inicial del flujo
 * @param finalNode el nodo final del flujo
 * 
 * @return Integer con el valor del flujo maximo
"""
def fordFulkerson(graph, initialPathNode, finalPathNode):
    # Crear el grafo residual a partir del original
    residualGraph = {node: {} for node in graph}
    for u in graph:
        for v, capacity in graph[u].items():
            residualGraph[u][v] = capacity
            # Iniciar las aristas inversas (0/capacidad) en el grafo residual con capacidad 0 si no existen
            if v not in residualGraph:
                residualGraph[v] = {}
            if u not in residualGraph[v]:
                residualGraph[v][u] = 0

    path = {} # Para almacenar el camino que aumenta
    maxFlow = 0 

    # Mientras haya un camino que aumenta desde el inicio al final
    while dfs(residualGraph, initialPathNode, finalPathNode, path, {node: False for node in residualGraph}):
        # Se encuentra la capacidad minima en el camino que aumenta
        pathFlow = float('Inf')
        s = finalPathNode
        while s != initialPathNode:
            pathFlow = min(pathFlow, residualGraph[path[s]][s])
            s = path[s]

        # Actualiza capacidades residuales en el camino
        v = finalPathNode
        while v != initialPathNode:
            u = path[v]
            residualGraph[u][v] -= pathFlow
            residualGraph[v][u] += pathFlow # Capacidad inversa para el camino de regreso
            v = path[v]
        
        maxFlow += pathFlow # Agregar el flujo del camino al flujo total

    return maxFlow