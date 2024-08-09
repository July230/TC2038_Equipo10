"""
Resulta que ha llegada una nueva máquina embotelladora de refrescos, el contenedor principal de la máquina
tiene forma cilindrica. Se sabe que cada envase de refresco debe contener M mililitros. Se desea saber
cuántos refrescos se puede llenar la máquina de un sola vez, sin recargar el contenedor. Solo se tiene los
datos del radio de la base y la altura medidos en metros.
"""

# Este función calcula la cantidad de envases enteros que puede llenar la máquina en ún recargo
def llenaEnvase(radius,height,mils):
    volMaquina = pow(radius,2)*height
    numBottles = volMaquina // (mils / 10e6)
    return numBottles

RAD = int(input("Cual radio tiene el base?\n"))
HEIGHT = int(input("Cual altura tiene el contenedor?\n"))
MIL = int(input("Cual volumen en mililitros tiene el envase?\n"))

numBottles = llenaEnvase(RAD,HEIGHT,MIL)

print("Numero de envases llenados:", numBottles)