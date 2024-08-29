/*
Este programa busca resolver el problema de cambio de monedas.
El programa recibe un numero entero N, seguido de N valores enteros (uno en cada línea, no necesariamente están ordenados) 
que representan las diferentes denominaciones disponibles de las monedas. 
Seguido de esto, el programa recibe dos números enteros: P y Q, (uno en cada línea) por la entrada estándar, 
que representan P: el precio de un producto dado y Q: es el billete o moneda con el que se paga dicho producto.

La salida del programa es una lista de N valores correspondientes al número de monedas de cada denominación, 
de mayor a menor, una en cada línea, que se tienen que dar para dar el cambio por el producto pagado, utilizando un algoritmo avaro. 

Autores: Maarten van 't Hoff A01764070 y Ian Julian Estrada Castro A01352823
Fecha: 01/09/2024

*/

#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

void fillVector(vector<int>& array){
    for(int i = 0; i < array.size(); i++){
        array[i] = (rand() % 100) + 1;
    }
}


int main(){
    int size = 10;
    vector<int> array(size);

    for(int i = 0; i < size; i++){
        cout << array[i] << " ";
    }
    fillVector(array);
    cout << endl;

    cout << "Vector con numeros aleatorios" << endl;
    for(int i = 0; i < size; i++){
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}