"""
Se desea calcular el factorial de un numero dado por el usuario
"""

def factorial(n):
    n = int(n)
    fact = 1
    if n < 0:
        print("Factorial no existe")
        return 0
    for i in range(1,n):
        fact *= i
    print("Factorial es:", fact)
    return fact

N = input("De cual numero quieres calcular el factorial?\n")

factorial(N)