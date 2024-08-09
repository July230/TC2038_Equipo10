import numpy as np

def cuentaDias(camisas,linea1,linea2):
    dias = 0
    prod = 0
    if camisas > prod:
        prod += linea1 + linea2
        dias += 1

    elif camisas < prod:
        dias = 1
    return dias

#linea1=np.random.randint(0,10)