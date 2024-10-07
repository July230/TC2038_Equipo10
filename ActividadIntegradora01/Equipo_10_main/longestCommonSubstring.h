#include "header.h"

// Encuentra la subcadena común más larga
// Complejidad: O(n*m)
std::string longestCommonSubstring(std::string s1, std::string s2) {

    // Tamaño de las cadenas
    int n = s1.size();
    int m = s2.size();

    // Crear matriz dp de tamaño (n+1) x (m+1)
    std::vector<std::vector<int>> dp(n+1, std::vector<int>(m+1));

    // Inicializar variables
    int max = 0;
    int end = 0;

    // Recorrer las cadenas
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            // Si los caracteres son iguales
            if (s1[i-1] == s2[j-1]) {

                // Asignar a dp[i][j] el valor de dp[i-1][j-1] + 1
                dp[i][j] = dp[i-1][j-1] + 1;

                // Si dp[i][j] es mayor que max
                if (dp[i][j] > max) {

                    // Asignar a max el valor de dp[i][j]
                    max = dp[i][j];

                    // Asignar a end el valor de i
                    end = i;
                }
            }
        }
    }

    // Regresar la subcadena común más larga
    return s1.substr(end-max, max);
}

// Encuentra las posiciones de la subcadena común más larga
// Complejidad: O(n*m)
std::vector<std::pair<int,int>> longestCommonSubstringPositions(std::string s1, std::string s2) {

    // Subcadena común más larga
    std::string lcs = longestCommonSubstring(s1, s2);

    // Tamaño de la subcadena común más larga
    int l = lcs.size();

    // Tamaño de la cadenas
    int n = s1.size();

    // Crear vector de pares de enteros
    std::vector<std::pair<int,int>> positions;

    // Recorrer la cadena s1
    for (int i = 0; i <= n - l; i++) {

        // Si la subcadena común más larga es igual a la subcadena de s1
        if (lcs == s1.substr(i, l)) {

            // Agregar a positions el par (i, i+l)
            positions.push_back(std::make_pair(i, i+l));
        }
    }

    // Regresar vector de pares de enteros
    return positions;
}