"""
Este programa muestra los números, la suma y promedio de la serie
3, 6, 9, 12, ... 99
"""

# numeros(), solución iterativa que utiliza un ciclo que inicia en 3 y se suma de 3 en 3 hasta llegar a 99
# por cada iteración, se suma el valor actual al acumulador suma y 1 al contador, se imprimen los valores de i
# se obtiene el promedio al terminar el ciclo
def numeros():
    suma = 0
    promedio = 0
    count = 0
    for i in range(3, 100, 3):
        print(i)
        suma += i
        count += 1
    
    promedio = suma / count
    print ("Suma total: ", suma)
    print("Promedio: ", promedio)
    
    return suma

numeros()

# numeros(), solución recursiva cuyo caso base es: si i llega a 100, termina la recursion y se obtiene el promedio
# cada vez que es llamada, los valores de i se suman al acumulador suma y 1 al contador
# se llama la funcion con los valores actuales de i, suma y count
def numerosRecursivo(i=3, suma=0, count=0):
    if i >= 100:
        promedio = suma / count
        print ("Suma total: ", suma)
        print("Promedio: ", promedio)
        return suma
    
    print(i)

    suma += i
    count += 1

    return numerosRecursivo(i + 3, suma, count)

numerosRecursivo()