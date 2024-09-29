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
#include <iomanip>
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

    // Remove last element of array which is newline
    if (!tempArr.empty() && tempArr.back() == '\n'){
        tempArr.pop_back();
    }

    int numRows = (tempArr.size() + length - 1) / length;

    for (int i = 0; i < numRows; i++){
        vector<char> row;
        for (int j = 0; j < length; j++){
            if (i * length + j < tempArr.size()){
                row.push_back(tempArr[i * length + j]); // Push each element to the back of the corresponding row
            }
            else{
                row.push_back('\0'); // If we have reached end of text array, fill the rest with null characters
            }
        }
        arr.push_back(row); // Push row to back of the full array, reshaping the text file
    }

    return arr;
}

vector<int> calcHash(vector<vector<char>> &arr, int length){
    vector<int> result;
    int colResult = 0;
    for (int i = 0; i < length; i++){
        colResult = 0; // For each column, reset the result calculator
        for (int j = 0; j < arr.size(); j++){
            if (arr[j][i] == '\0'){
                colResult += length; // If null character then sum user input
            }
            else{
                colResult += arr[j][i]; // Sum other ASCII values
            }
        }
        colResult = colResult % 256; // Calculate hash value
        result.push_back(colResult); // Send value to back of result array
    }
    return result;
}

int main(){
    int n;
    string fileName;
    vector<vector<char>> str;
    vector<int> result;

    cout << "Ingrese el nombre del archivo de texto (sin extension): "; getline(cin, fileName);
    ifstream file(fileName + ".txt");
    if (!file){ // Check if the filename exists within the provided directory
        cerr << "Archivo de texto " << fileName << ".txt no existe" << endl; // Return error text
        return -1; // Return error code
    }
    file.close();


    cout << "Ingrese un multiplo 'n' de 4 entre 16 y 64: "; cin >> n;
    if (n < 16 || n % 4 != 0){ // Check if value is valid for hash calculation
        cerr << "Numero invalido" << endl;
        return -1;
    }

    str = constructArr(fileName, n);

    // Print the values of the reshaped text array
    cout << "Matriz generada por el algoritmo, los saltos de linea se representan con '-' y espacios rellenados con '['" << endl;
    for (int i = 0; i < str.size(); i++){ // arr.size() takes the outermost dimension, which are the rows
        for (int j = 0; j < n; j++){ // n provides the amount of columns
            if (str[i][j] == '\n'){
                cout << "-" << " "; // Fill LF characters with '-'
            }
            else if (str[i][j] == '\0'){
                cout << "[" << " "; // Fill null characters with '-'
            }
            else{
                cout << str[i][j] << " ";
            }
        }
        cout << endl;
    }

    result = calcHash(str, n);

    // Print the values of the calculated hash
    cout << "Arreglo de longitud 'n' que muestra la suma de las columnas con el modulo 256" << endl;
    for (int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;

    cout << "Representacion hexadecimal" << endl;
    for (int i = 0; i < result.size(); i += 2){
        cout << hex << uppercase << setfill('0') << setw(2) << result[i]; // Asures all hex values are of 2 digits using setfill and setw
        cout << setfill('0') << setw(2) << result[i+1] << " ";
    }
    cout << nouppercase << dec << endl;

    return 0;
}
