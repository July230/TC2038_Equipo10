"""
Este programa calcula los primeros 15 numeros de una sumatoria especifica
"""

# Esto es una opcion iterative en cual se usa al variable i para sumar los fracciones

def fracSquareSum(n):
    sum = 0
    for i in range(1,n):
        sum += pow(1/i, 2)
    return sum

N = 15
sum = fracSquareSum(N)
print("Suma total:", sum)