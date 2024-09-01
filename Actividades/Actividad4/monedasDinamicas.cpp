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
    vector< vector<int> > nums(array.size(), vector<int>(value + 1, INT_MAX));
    vector<int> cambio(array.size(),0);

    for (currency = 0; currency < array.size(); currency++){
        nums[currency][0] = 0;
    }

    for (currency = 0; currency < array.size(); currency++){
        for (val = 1; val <= value; val++){
            if (currency > 0) {
                nums[currency][val] = nums[currency - 1][val];
            }
            if (val >= array[currency] && nums[currency][val - array[currency]] != INT_MAX) {
                nums[currency][val] = min(nums[currency][val], 1 + nums[currency][val - array[currency]]);
            }
        }
    }

    currency = array.size() - 1;
    val = value;

    while (val > 0 && currency >= 0){
        if (currency > 0 && nums[currency][val] == nums[currency-1][val]){
            currency -= 1;
        }
        else{
            cambio[currency] += 1;
            val -= array[currency];
        }
    }

    cout << "Cambio PD:" << endl;
    for(int i = 0; i < array.size(); i++){
        cout << cambio[i] << " ";
    }
    cout << endl;

    return cambio;
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

    monedaDinamica(array, value);

    return 0;
}