/*
Este programa busca resolver el problema de cambio de monedas.
El programa recibe un numero entero N, seguido de N valores enteros (uno en cada línea, no necesariamente están ordenados) 
que representan las diferentes denominaciones disponibles de las monedas. 
Seguido de esto, el programa recibe dos números enteros: P y Q, (uno en cada línea) por la entrada estándar, 
que representan P: el precio de un producto dado y Q: es el billete o moneda con el que se paga dicho producto.

La salida del programa es una lista de N valores correspondientes al número de monedas de cada denominación, 
de mayor a menor, una en cada línea, que se tienen que dar para dar el cambio por el producto pagado, utilizando un algoritmo
de programicion dinamica y un algoritmo avaro. 

Autores: Maarten van 't Hoff A01764070 y Ian Julian Estrada Castro A01352823
Fecha: 01/09/2024

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <stdlib.h>

using namespace std;

void fillVector(vector<int>& array){
    for(int i = 0; i < array.size(); i++){
        array[i] = (rand() % 20) + 1;
    }
}

vector<int> monedaDinamica(vector<int>& array, int value){
    int val, currency;

    // Inicializamos el array nums con INT_MAX para los casos cuales son "imposibles" (cambio que no puede existir)
    vector< vector<int> > nums(array.size(), vector<int>(value + 1, INT_MAX));
    vector<int> cambio(array.size(),0);

    // Todas las monedas tienen 0 al principio, asi lo inicializamos la primera columna.
    for (currency = 0; currency < array.size(); currency++){
        nums[currency][0] = 0;
    }

    // Usamos el algoritmo dinamico para buscar la menor cantidad de monedas.
    for (currency = 0; currency < array.size(); currency++){
        for (val = 1; val <= value; val++){
            if (currency > 0) {
                nums[currency][val] = nums[currency - 1][val];
            }
            if (val >= array[currency] && nums[currency][val - array[currency]] != INT_MAX) { // Miramos si el cambio lleva INT_MAX en una celda para que no llevamos casos imposibles
                nums[currency][val] = min(nums[currency][val], 1 + nums[currency][val - array[currency]]);
            }
        }
    }

    currency = array.size() - 1;
    val = value;

    // Usamos un segundo algoritmo dinamico para hacer el array de cambio en termino del array nums
    while (val > 0 && currency >= 0){
        if (currency > 0 && nums[currency][val] == nums[currency-1][val]){
            currency -= 1; // Si las monedas de diferente valor traen la misma cantidad, cambiamos a ella
        }
        else{
            cambio[currency] += 1; // Si no incrementamos esa valor de moneda y vamos bajando el array nums
            val -= array[currency];
        }
    }

    return cambio;
}

vector<int> monedaAvaro(vector<int>& monedas, int cantidad){
    vector<int> result(monedas.size(), 0); // Arreglo del mismo tamanio con todos los elementos en 0
    int sumaS = 0;

    // Mientras la cantidad actual sea mayor a la denominacion actual, se resta
    // la denominacion y se incrementa el conteo en el arreglo de resultados
    for(int i = monedas.size() - 1; i >= 0; i--){
        while(sumaS + monedas[i] <= cantidad){
            sumaS += monedas[i];
            result[i]++;
        }
    }

    if(sumaS != cantidad){
        cout << "No se puede hacer un cambio exacto con las monedas disponibles" << endl;
    }

    return result;
}

int main(){
    srand(time(0));
    int size = 10;
    vector<int> array(size);
    fillVector(array);
    sort(array.begin(), array.end());

    int value;
    cout << "Valor de cambio: "; cin >> value;
    
    cout << "Vector con numeros aleatorios:" << endl;
    for(int i = 0; i < size; i++){
        cout << array[i] << " ";
    }
    cout << endl;

    vector<int> cambio = monedaDinamica(array, value);

    cout << "Cambio PD:" << endl;
    for(int i = 0; i < array.size(); i++){
        cout << cambio[i] << " ";
    }
    cout << endl;

    cambio = monedaAvaro(array,value);

    cout << "Cambio Avaro:" << endl;
    for(int i = 0; i < array.size(); i++){
        cout << cambio[i] << " ";
    }
    cout << endl;


    return 0;
}