/*
El programa recibe el nombre de un archivo de texto (datos.txt), 
seguido de un entero n, donde n es un entero múltiplo de 4 y (16 <= n <=64).
La salida es una cadena de longitud n/4 que es una representación hexadecimal 
que corresponde al hasheo del archivo de texto de entrada de acuerdo con las siguientes reglas:

El entero n determina el número de columnas que contendrá una tabla donde se irán acomodando 
los caracteres del archivo de texto (incluyendo saltos de líneas) en los renglones que sean necesarios.

Si el número de caracteres en el archivo de entrada no es múltiplo de n, el último renglón se "rellena" con el valor de n.

En un arreglo a de longitud n se calcula a[i] = (la suma de los ASCII de cada char en la columna) % 256.

La salida se genera concatenando la representación hexadecimal (mayúsculas) a dos dígitos de cada posición en el arreglo.

La longitud de la cadena de salida será de n/4.

Muestra la tabla generada, el arreglo a, y la cadena de salida.

Autores: Maarten van 't Hoff A01764070, Ian Julian Estrada Castro A01352823, Diego García A01710777
Fecha: 25/09/2024
*/

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

vector<vector<char>> constructArr(string fileName, int length){
    fstream newfile;
    string str;
    vector<char> tempArr;
    vector<vector<char>> arr;

    // Read the txt file into a unidimensional array of chars
    newfile.open(fileName + ".txt",ios::in); // Open file object to read
    if (newfile.is_open()){
        while(getline(newfile, str)){
            for (int i = 0; i < str.length(); i++){
                tempArr.push_back(str[i]);
            }
            tempArr.push_back('\n');
        }
        newfile.close(); // Close file object
    }

    int numRows = (tempArr.size() + length - 1) / length;

    for (int i = 0; i < numRows; i++){
        vector<char> row;
        for (int j = 0; j < length; j++){
            if (i * length + j < tempArr.size()){
                row.push_back(tempArr[i * length + j]);
            }
            else{
                row.push_back('\0');
            }
        }
        arr.push_back(row);
    }

    return arr;
}

int calcHash(){
    
}

int main(){
    int n;
    string fileName;
    vector<vector<char>> str;

    cout << "Ingrese el nombre del archivo de texto (sin extension): "; getline(cin, fileName);
    ifstream file(fileName + ".txt");
    if (!file){
        cerr << "Archivo de texto " << fileName << ".txt no existe" << endl;
        return -1;
    }
    file.close();


    cout << "Ingrese un multiplo 'n' de 4 entre 16 y 64: "; cin >> n;
    if (n < 16 || n % 4 != 0){
        cout << "Numero invalido" << endl;
        return -1;
    }

    str = constructArr(fileName, n);

    for (const auto& row : str){
        for (const char& c : row){
            if (c == '\n'){
                cout << "-" << " ";
            }
            else if (c == '\0'){
                cout << "[" << " ";
            }
            else{
                cout << c << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
