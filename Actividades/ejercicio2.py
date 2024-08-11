"""
Resulta que ha llegada una nueva máquina embotelladora de refrescos, el contenedor principal de la máquina
tiene forma cilindrica. Se sabe que cada envase de refresco debe contener M mililitros. Se desea saber
cuántos refrescos se puede llenar la máquina de un sola vez, sin recargar el contenedor. Solo se tiene los
datos del radio de la base y la altura medidos en metros.
Maarten van 't Hoff A01764070, Ian Julian Estrada Castro A01352823
Fecha: 09/08/2024
"""
import math
# Este función calcula la cantidad de envases enteros que puede llenar la máquina en ún recargo
def llenaEnvase(radius,height,mils):
    volMaquina = pow(radius,2)*height*math.pi
    numBottles = volMaquina // (mils / 1e6)
    return numBottles

RAD = float(input("Cual radio tiene el base?\n"))
HEIGHT = float(input("Cual altura tiene el contenedor?\n"))
MIL = float(input("Cual volumen en mililitros tiene el envase?\n"))

numBottles = llenaEnvase(RAD,HEIGHT,MIL)

print("Numero de envases llenados:", numBottles)