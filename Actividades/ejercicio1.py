"""
Este programa calcula a los dias requiridos para producir a una cantidad de camisas N, que es entrado por el usuario.
Maarten van 't Hoff A01764070, Ian Julian Estrada Castro A01352823
Fecha: 09/08/2024
"""
import numpy as np

# La función cuentaDias toma como unico parametro la cantidad de camisas cual queremos producir.
# Este parametro es definido por el usuario más tarde en el código.
# La función mira si se falta producir alguna cantidad de camisas, hasta que la cantidad que falta de producir es igual o menos a 0.
# Cada ciclo los dos lineas producen una cantidad de camisas aleatorio entre 0 y 9.
# Miramos a varios casos para que podemos producir la maxima cantidad de camisas o solo producimos camisas por parte de una linea.
# Cada iteración es igual a ún día, así que agregamos una día a días cada ciclo.
# La función termina cuando falta <= 0 y retorno la cantidad de días (o ciclos) que paso para terminar.
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