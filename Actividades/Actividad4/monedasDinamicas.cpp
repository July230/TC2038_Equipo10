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
    vector< vector<int> > nums(array.size(), vector<int>(value + 1));
    vector<int> cambio(array.size());

    for (currency = 0; currency < array.size(); currency++){
        nums[currency][0] = 0;
        for (val = 1; val <= value; val++){
            if (currency == 0){
                nums[currency][val] = nums[currency][val - 1];
                if (val % array[currency] == 0){
                    nums[currency][val] += 1;
                }
            }
            else if (val < array[currency]){
                nums[currency][val] = nums[currency - 1][val];
            }
            else{
                nums[currency][val] = min(nums[currency - 1][val], 1 + nums[currency][val - array[currency]]);
            }
        }
    }

    // cout << "Init arr " << endl;
    // for(int i = 0; i < array.size(); i++){
    //     for(int j = 0; j <= value; j++){
    //         cout << nums[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // cout << "minCoins " << nums[array.size() - 1][value] << endl;

    currency = array.size() - 1;
    val = value;

    while (nums[currency][val] != 0){
        if (nums[currency][val] == nums[currency-1][val]){
            currency -= 1;
        }
        else if (nums[currency][val] == 1 + nums[currency][val - array[currency]]){
            cambio[currency] += 1;
            val -= array[currency];
        }
    }

    cout << "Change arr " << endl;
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

    int value = (rand() % (100/array[0])) * array[0];

    cout << "Valor de cambio: " << value << endl;
    
    cout << "Vector con numeros aleatorios" << endl;
    for(int i = 0; i < size; i++){
        cout << array[i] << " ";
    }
    cout << endl;

    monedaDinamica(array, value);

    return 0;
}