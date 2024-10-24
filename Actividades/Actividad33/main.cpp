

#include "knapsack.h"

using namespace std;

int main(){
    int N = 3;
    vector<int> valores = {1, 2, 3};
    vector<int> pesos = {4, 5, 1};
    int W = 4;

    int beneficio = knapSack(N, valores, pesos, W);

    cout << "Beneficio optimo: " << beneficio << endl;

    return 0;
}