#include "header.h"
#include "stringSearch.h"

int main(){
    std::string pattern = "aaa";
    std::string text = "aabaaabaaabaabaaa";
    std::string concat = pattern + '\0' + text;
    
    std::vector<int> index;

    stringSearch(concat, index, pattern.length());

    if (index.size() == 0){
        std::cout << "(false) Cadena no encontrada en la transmission" << std::endl;
    }
    else{
        for (int i = 0; i < index.size(); i++){
            std::cout << "(true) Posicion inicial: " << index[i] <<
            " Posicion final: " << index[i] + pattern.length() - 1 << std::endl;
        }
    }
    return 0;
}