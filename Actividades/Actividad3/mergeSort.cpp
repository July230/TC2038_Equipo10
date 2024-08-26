/*
Este programa aplica la tecnica divide y venceras a traves del algoritmo de ordenamiento MergeSort de mayor a menor
Autores: Maarten van 't Hoff A01764070 y Ian Julian Estrada Castro A01352823
Fecha: 25/08/2024

Idea de https://www.geeksforgeeks.org/python-program-for-merge-sort/
*/

#include <vector>
#include <iostream>
using namespace std;

void merge(vector<double>& arr, int left, int mid, int right){
    int mid1 = mid - left + 1;
    int mid2 = right - mid;

    // Arreglos temporales
    vector<double> tempLeft(mid1), tempRight(mid2);

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
        if (tempLeft[i] >= tempRight[j]){
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

void sort(vector<double>& arr, int left, int right){
    if (left >= right){
        return;
    }
    
    int mid = left + (right - left) / 2;
    sort(arr, left, mid);
    sort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main(){
    vector<double> arr = {83.0, 60.0, 1.0, 25.0, 67.0, 47.0, 11.0, 44.0, 47.0};
    vector<double> arr1 = {5.0, 3.0, 7.0, 9.0, 6.0, 2.0, 8.0, 1.0, 10.0, 4.0};
    vector<double> arr2 = {35.0, 45.0, 67.0, 33.0, 29.0, 56.0, 49.0, 97.0, 11.0, 51.0, 75.0, 81.0, 72.0, 90.0, 87.0, 100.0, 45.0, 20.0, 89.0};
    vector<double> arr3 = {1.0, -2.0, 7.0, 10.0, -1.0, 5.0, -5.0, 6.0, 4.0, -7.0, 8.0, -9.0, -3.0, -10.0};
    int n = arr.size();
    int m = arr1.size();
    int u = arr2.size();
    int v = arr3.size();

    cout << "Iniciando casos prueba" << endl;

    for (int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    sort(arr, 0, n-1);
    for (int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }

    cout << endl;
    cout << endl;

    for (int i = 0; i < arr1.size(); i++){
        cout << arr1[i] << " ";
    }
    cout << endl;
    sort(arr1, 0, m-1);
    for (int i = 0; i < arr1.size(); i++){
        cout << arr1[i] << " ";
    }

    cout << endl;
    cout << endl;

    for (int i = 0; i < arr2.size(); i++){
        cout << arr2[i] << " ";
    }
    cout << endl;
    sort(arr2, 0, u-1);
    for (int i = 0; i < arr2.size(); i++){
        cout << arr2[i] << " ";
    }

    cout << endl;
    cout << endl;

    for (int i = 0; i < arr3.size(); i++){
        cout << arr3[i] << " ";
    }
    cout << endl;
    sort(arr3, 0, v-1);
    for (int i = 0; i < arr3.size(); i++){
        cout << arr3[i] << " ";
    }
}