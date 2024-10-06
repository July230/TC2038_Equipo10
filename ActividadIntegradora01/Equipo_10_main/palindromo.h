#ifndef PALINDROMO
#define PALINDROMO

#include "header.h"

using namespace std;

string preProcesar(const string& s){
    string result = "^"; // Se usa un caracter no presente en la cadena como delimitador.
    for(int i = 0; i < s.length(); i++){
        result += "#" + s.substr(i, 1);
    }
    result += "#$"; // Delimitador para evitar desbordamientos
    return result;
}

// manacher utiliza el algoritmo manacher para encontrar el codigo espejeado (palindromo) mas largo
pair<int, int> manacher(const string& s){
    string T = preProcesar(s);
    int palindromoSize = T.size();
    vector<int> palindromo(palindromoSize, 0); // Array de longitud del palindromo
    int centro = 0; // Centro del palindromo actual
    int derecha = 0; // Borde derecho del palindromo
    int maxLen = 0; // Longitud máxima del palindromo encontrado
    int centerIndex = 0; // Indice del centro del palindromo mas largo

    for(int i = 0; i < palindromoSize - 1; i++){
        int espejo = 2 * centro - i; // Posicion del espejo i en relacion con centro

        // Inicializar palindromo[i] al valor mínimo entre el espejo de i y el borde derecho.
        if(derecha > i){
            palindromo[i] = min(derecha - i, palindromo[espejo]);
        }

        // Expandir el palindromo centrado en i
        while(T[i + 1 + palindromo[i]] == T[i - 1 - palindromo[i]]){
            palindromo[i]++;
        }

        // Si el palindromo va mas alla de derecha, ajustar centro y derecha
        if(i + palindromo[i] > derecha){
            centro = i;
            derecha = i + palindromo[i];
        }

        // Actualizar el palindromo mas largo encontrado
        if(palindromo[i] > maxLen){
            maxLen = palindromo[i];
            centerIndex = i;
        }
    }

    // Convertir la posicion en la cadena original quitando caracteres agregador
    int start = (centerIndex - 1 - maxLen) / 2;
    int end = start + maxLen - 1;

    pair<int, int> resultado;
    resultado.first = start; // Retornamos posiciones 1-based
    resultado.second = end;

    return resultado; 

}

#endif