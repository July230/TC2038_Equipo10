"""
Este programa muestra solicita un número que indica cuantos números aleatorios (positivos y negativos)
se mostrarán
"""

import numpy as np

numeros = int(input("¿Cuántos números quieres? \n"))
                        # Desde, Hasta, Cantidad de numeros
numAleatorios = np.random.randint(-9, 9, numeros)

print(numAleatorios)