# El programa recibe un string, calcula el arreglo de substrings y lo muestra ordenado alfabéticamente.

str = input("Ingrese un string: ")

substrings = []

for i in range(len(str)):
    substrings.append([i, str[i:]])
    if i == len(str) - 1:
        substrings.append([i + 1, '$'])



print(substrings)