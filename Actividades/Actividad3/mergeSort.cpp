/*
Este programa aplica la tecnica divide y venceras a traves del algoritmo de ordenamiento MergeSort de mayor a menor
Autores: Maarten van 't Hoff A01764070 y Ian Julian Estrada Castro A01352823
Fecha: 25/08/2024

Idea de https://www.geeksforgeeks.org/python-program-for-merge-sort/
*/

#include <vector>
#include <iostream>
using namespace std;

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

void sort(vector<int>& arr, int left, int right){
    if (left >= right){
        return;
    }
    
    int mid = left + (right - left) / 2;
    sort(arr, left, mid);
    sort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main(){
    // Caso normal
    vector<int> arr1 = {83, 60, 1, 25, 67, 47, 11, 44, 47, 45};
    int n = arr1.size();

    sort(arr1, 0, n-1);

    cout << "Sorted array 1\n";
    for (int i = 0; i < arr1.size(); i++){
        cout << arr1[i] << " ";
    }

    // Caso con numeros grandes (incluye int mas grande en C++)
    vector<int> arr2 = {1919599943, 1233349748, 1957834318, 2147483647, 1691781089, 1029790136, 376656260, 1850878874, 1231883793, 423604860};

    n = arr2.size();
    sort(arr2, 0, n-1);

    cout << "\nSorted array 2\n";
    for (int i = 0; i < arr2.size(); i++){
        cout << arr2[i] << " ";
    }

    // Caso con numero un numero negativo
    vector<int> arr3 = {79, -50, 13, 62, 91, 20, 49, 17, 96, 14};

    n = arr3.size();
    sort(arr3, 0, n-1);

    cout << "\nSorted array 3\n";
    for (int i = 0; i < arr3.size(); i++){
        cout << arr3[i] << " ";
    }

    // Caso con un zero
    vector<int> arr4 = {-91, -46, -5, -45, 0, 91, 20, 75, 23, 33};

    n = arr4.size();
    sort(arr4, 0, n-1);

    cout << "\nSorted array 4\n";
    for (int i = 0; i < arr4.size(); i++){
        cout << arr4[i] << " ";
    }
}