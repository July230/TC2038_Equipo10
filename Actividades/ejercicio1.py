"""
Este programa calcula a los dias requiridos para producir a una cantidad de camisas N, que es entrado por el usuario.
Maarten van 't Hoff A01764070, Ian Julian Estrada Castro A01352823
Fecha: 09/08/2024
"""
import numpy as np

def cuentaDias(camisas):
    dias = 0
    falta = camisas

    while falta > 0:

        linea1 = np.random.randint(0,9)
        linea2 = np.random.randint(0,9)
        maxProd = linea1 + linea2
        dias += 1

        if falta > maxProd:
            falta -= maxProd
        
        elif falta > linea1 and falta > linea2:
            falta -= max(linea1, linea2)
        
        elif falta <= linea1 or falta <= linea2:
            falta -= min(linea1, linea2)
    
    return dias

N = int(input("Cuantas camisas quieres producir?\n"))
dias = cuentaDias(N)
print("Dias de producción:",dias)