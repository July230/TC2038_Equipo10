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
    int n = arr.size();

    sort(arr, 0, n-1);

    for (int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
}