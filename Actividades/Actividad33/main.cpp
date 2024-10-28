#include "knapsack.h"

using namespace std;

int main(){

    // TEST 1

    int n_1 = 3;
    vector<int> valores_1 = {1, 2, 3};
    vector<int> pesos_1 = {4, 5, 1};
    int w_1 = 4;

    cout << "TEST 1: " << endl;

    int beneficio_1 = knapSack(n_1, valores_1, pesos_1, w_1);

    cout << "Beneficio optimo: " << beneficio_1 << endl;
    cout << endl;

    // TEST 2

    int n_2 = 6;
    vector<int> valores_2 = {2, 5, 6, 10, 13, 16};
    vector<int> pesos_2 = {1, 2, 4, 5, 7, 8};
    int w_2 = 8;

    cout << "TEST 2: " << endl;

    int beneficio_2 = knapSack(n_2, valores_2, pesos_2, w_2);

    cout << "Beneficio optimo: " << beneficio_2 << endl;
    cout << endl;

    // TEST 3

    int n_3 = 4;
    vector<int> valores_3 = {1, 2, 3, 4};
    vector<int> pesos_3 = {1, 2, 3, 4};
    int w_3 = 5;

    cout << "TEST 3: " << endl;

    int beneficio_3 = knapSack(n_3, valores_3, pesos_3, w_3);

    cout << "Beneficio optimo: " << beneficio_3 << endl;
    cout << endl;

    // TEST 4

    int n_4 = 3;
    vector<int> valores_4 = {1, 4, 5};
    vector<int> pesos_4 = {3, 4, 5};
    int w_4 = 7;

    cout << "TEST 4: " << endl;
    
    int beneficio_4 = knapSack(n_4, valores_4, pesos_4, w_4);

    cout << "Beneficio optimo: " << beneficio_4 << endl;
    cout << endl;


    return 0;
}