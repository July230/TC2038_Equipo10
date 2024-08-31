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
        array[i] = (rand() % 500) + 1;
    }
}

// La funcion merge hace la mezcla en los subarreglos
void merge(vector<int>& arr, int left, int mid, int right){
    int mid1 = mid - left + 1;
    int mid2 = right - mid;

    // Arreglos temporales
    vector<int> tempLeft(mid1), tempRight(mid2);

    for (int i = 0; i < mid1; i++){
        tempLeft[i] = arr[left + i];
    }

    for (int j = 0; j < mid2; j++){
        tempRight[j] = arr[mid + 1 +j];
    }

    int i = 0, j = 0;
    int k = left;

    // Mezclar los arreglos temporales
    while (i < mid1 && j < mid2){
        if (tempLeft[i] <= tempRight[j]){
            arr[k] = tempLeft[i];
            i++;
        }
        else{
            arr[k] = tempRight[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes de tempLeft
    while (i < mid1){
        arr[k] = tempLeft[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de tempRight
    while (j < mid2){
        arr[k] = tempRight[j];
        j++;
        k++;
    }
}

// La funcion sort aplica el algoritmo MergeSort que consiste en dividir el arreglo
// en arreglos mas pequenios para ordenarlos y finalmente mezclar todos los arreglos en uno
// Complejidad temporal de O(nlog(n))
void sort(vector<int>& arr, int left, int right){
    if (left >= right){
        return;
    }
    
    int mid = left + (right - left) / 2;
    sort(arr, left, mid);
    sort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void changeCoins(vector<int>& monedas, int cantidad){
    vector<int> result;

    // Mientras la cantidad actual sea mayor a la denominacion actual, se resta
    // la denominacion y se agrega al arreglo de resultados
    for(int i = 0; i <= monedas.size() - 1; i++){
        while(cantidad >= monedas[i]){
            cantidad -= monedas[i];
            result.push_back(monedas[i]);
        }
    }

    if(cantidad != 0){
        cout << "No se puede hacer un cambio exacto con las monedas disponibles" << endl;
    } else {
        cout << "Cambio: ";
        for (int moneda : result){
            cout << moneda << " ";
        }
        cout << endl;
    }

}

int main(){
    int size = 10;
    int cantidad;
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
    sort(array, 0, size-1);
    cout << "Vector ordenado" << endl;
    for(int i = 0; i < size; i++){
        cout << array[i] << " ";
    }
    cout << endl;

    cout << "Ingrese la cantidad a cambiar: ";
    cin >> cantidad;

    // Obtener el cambio
    changeCoins(array, cantidad);

    return 0;
}