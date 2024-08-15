"""
Este programa calcula los primeros 15 numeros de una sumatoria especifica
Maarten van 't Hoff A01764070, Ian Julian Estrada Castro A01352823
Fecha: 09/08/2024
"""

# Esto es una opcion iterative en cual se usa al variable i para sumar los fracciones.
# Dependiente del número sumado el numero es elevado a otro numero.
# Si es un número de pares lo cuadramos. Si es un número de impares el exponente trae el mismo numero.

def fracSquareSum(n):
    sum = 0
    for i in range(1,n):
        if i%2 == 0:
            sum += pow(1/i, 2)
        else:
            sum += pow(1/i,i)
    return sum

N = 15
sum = fracSquareSum(N)
print("Suma total:", sum)

