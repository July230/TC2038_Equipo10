""" 
Este programa aplica la tecnica divide y venceras a traves del algoritmo de ordenamiento MergeSort de mayor a menor
Autores: Maarten van 't Hoff A01764070 y Ian Julian Estrada Castro A01352823
Fecha: 25/08/2024

Idea de https://www.geeksforgeeks.org/python-program-for-merge-sort/
"""

def merge(array, left, medium, right):
    mid1 = medium - left + 1
    mid2 = right - medium

    # Arreglos temporales
    tempLeft = [0] * (mid1)
    tempRight = [0] * (mid2)

    # Copiar los datos a los arreglos temporales
    for i in range(0, mid1):
        tempLeft[i] = array[left + i]

    for j in range(0, mid2):
        tempRight[j] = array[medium + 1 + j]

    # Mezclar los arreglos temporales
    i = 0 # Primer indice del primer subarreglo
    j = 0 # Primer indice del segundo subarreglo
    k = left # Primer indice del arreglo mezclado

    while i < mid1 and j < mid2:
        if tempLeft[i] >= tempRight[j]:
            array[k] = tempLeft[i]
            i += 1
        else:
            array[k] = tempRight[j]
            j += 1
        k += 1
    
    # Copiar los elementos restantes de tempLeft
    while i < mid1:
        array[k] = tempLeft[i]
        i += 1
        k += 1

    # Copiar los elementos restantes de tempRight
    while j < mid2:
        array[k] = tempRight[j]
        j += 1
        k += 1
    
def mergeSort(array, left, right):
    if left < right:
        # En cada iteracion, el arreglo se divide en dos partes
        medium = left+(right-left) // 2

        # Ordenar primera y segunda mitad
        mergeSort(array, left, medium)
        mergeSort(array, medium + 1, right)
        merge(array, left, medium, right)


array = [3, 7, 5, 8, 6, 9, 1, 10, 2, 4]
size = len(array)

for i in range(size):
    print("%d" % array[i],end=" ")


mergeSort(array, 0, size - 1)
print("\n\nSorted array is")
for i in range(size):
    print("%d" % array[i],end=" ")