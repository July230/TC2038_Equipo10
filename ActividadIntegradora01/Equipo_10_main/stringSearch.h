#ifndef STRING_SEARCH
#define STRING_SEARCH

#include "header.h"

/* Uso de Z-algorithm para busqueda de strings. Es un algoritmo
más simple de entender y implementar que el KMP, aún tiene un
poco más de complejidad de espacio. */


void stringSearch(std::string& concat, std::vector<int>& index, int patLength){
    int stringLength = concat.length();
    std::vector<int> Z(stringLength);
    int left = 0, right = 0;
    int patIndex;

    for (int i = 0; i < stringLength; i++){
        if (i > right){
            left = i;
            right = i;

            while (right < stringLength && concat[right - left] == concat[right]){
                right++;
            }
            Z[i] = right - left;
            right--;
        }
        else {
            patIndex = i - left;

            if (Z[patIndex] < right - i + 1){
                Z[i] = Z[patIndex];
            }
            else{
                left = i;
                while (right < stringLength && concat[right - left] == concat[right]){
                    right++;
                }
                Z[i] = right - left;
                right--;
            }
        }

        if (Z[i] == patLength){
            index.push_back(i - (patLength + 1));
        }
    }
}

#endif