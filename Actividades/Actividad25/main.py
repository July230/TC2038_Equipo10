# El programa recibe un string, calcula el arreglo de substrings y lo muestra ordenado alfabéticamente.

# Autores Ian Julián Estrada Castro A01352823,  Maarten van 't Hoff A01764070 y Diego Antonio García Padilla A01710777

str = input("Ingrese un string: ")

substrings = []
sortedSubstrings =[]

# El ciclo imprime agrega strings al arreglo substrings, reduciendo su longitud por cada indice
# Complejidad O(n)
for i in range(len(str)):
    substrings.append([i, str[i:]])
    if i == len(str) - 1:
        # Agregar el sufijo $ al final
        substrings.append([i + 1, '$'])

print("Sufijos: ")
for i in substrings:
    print(i)

# Ordenar los sufijos lexicográficamente
# key es el parametro de ordenación, lambda define funciones anónimas
# x es cada elemento del arreglo, el parámetro es el segundo elemento de la tupla
# La función sorted en python tiene complejidad de O(nlog(n))
sortedSubstrings = sorted(substrings, key=lambda x: x[1])

print("Sufijos ordenados: ")
for i in sortedSubstrings:
    print(i)