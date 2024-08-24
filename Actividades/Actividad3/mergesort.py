""" 
Este programa aplica la tecnica divide y venceras a traves del algoritmo de ordenamiento MergeSort
Autores: Maarten van 't Hoff A01764070 y Ian Julian Estrada Castro A01352823
Fecha: 25/08/2024

"""

size = int(input("Array size"))
array = [size]

def mergeSort():
    left, right = 0, size -1
    return merge(array, left, right)

def merge(array, left, right, medium):
    arraySize = right-left+1
    
    return (array)

def swap(array, pos1, pos2):
    array[pos1], array[pos2] = array[pos2], array[pos1]
    return array