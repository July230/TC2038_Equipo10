"""
Se desea calcular el factorial de un numero dado por el usuario
Maarten van 't Hoff A01764070, Ian Julian Estrada Castro A01352823
Fecha: 09/08/2024
"""

def factorial(n):
    n = int(n)
    fact = 1
    if n < 0:
        print("Factorial no existe")
        return 0
    for i in range(1,n + 1):
        fact *= i
    print("Factorial es:", fact)
    return fact

N = input("De cual numero quieres calcular el factorial?\n")

factorial(N)