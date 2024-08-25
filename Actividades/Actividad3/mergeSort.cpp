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
    vector<int> arr = {83, 60, 1, 25, 67, 47, 11, 44, 47};
    int n = arr.size();

    sort(arr, 0, n-1);

    for (int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
}