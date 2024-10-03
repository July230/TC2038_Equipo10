/*
Suponiendo que el código malicioso tiene siempre código "espejeado" (palíndromos de chars), 
sería buena idea buscar este tipo de código en una transmisión. 
El programa busca si hay código "espejeado" dentro de los archivos de transmisión. 
(palíndromo a nivel chars, no meterse a nivel bits). 
El programa muestra en una sola línea dos enteros separados por un espacio correspondientes a la posición (iniciando en 1) en donde inicia y termina el código "espejeado" más largo (palíndromo) para cada archivo de transmisión. Puede asumirse que siempre se encontrará este tipo de código.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

string preProcesar(const string& s){
    string result = "^"; // Se usa un caracter no presente en la cadena como delimitador.
    for(int i = 0; i < s.length(); i++){
        result += "#" + s.substr(i, 1);
    }
    result += "#$"; // Delimitador para evitar desbordamientos
    return result;

}

int main(){
    string cadena;

    cout << "Escribe una cadena: ";
    cin >> cadena;

    cout << preProcesar(cadena);
}
