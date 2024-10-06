#include "header.h"
#include "readFile.h"
#include "palindromo.h"
#include "longestCommonSubstring.h"

int main(){
    std::string mCodeFolder = "./mCode/";
    std::string txtFolder = "./transmission/";

    std::vector<std::string> mCode = {"mCode01", "mCode02", "mCode03"};
    std::vector<std::string> txt = {"transmission01", "transmission02"};


    std::vector<std::string> transmissions;
    std::vector<std::string> patterns;

    for (int i = 0; i < mCode.size(); i++){
        patterns.push_back(readFile(mCodeFolder, mCode[i]));
    }

    for (int i = 0; i < txt.size(); i++){
        transmissions.push_back(readFile(txtFolder, txt[i]));
    }

    std::cout << "Transmissions:" << std::endl << std::endl;

    for (int i = 0; i < transmissions.size(); i++){

        std::cout << "Transmission " << i+1 << ":" << std::endl;

        for (int j = 0; j < transmissions[i].length(); j++){
            std::cout << transmissions[i][j];
        }

        std::cout << "\n" << std::endl;
    }

    std::cout << "Malicious Code:" << std::endl << std::endl;

    for (int i = 0; i < patterns.size(); i++){

        std::cout << "Malicious Code " << i+1 << ":" << std::endl;

        for (int j = 0; j < patterns[i].length(); j++){
            std::cout << patterns[i][j];
        }

        std::cout << "\n" << std::endl;
    }


    // Encontrar el substring más largo común entre las transmisiones

    std::string lcs = longestCommonSubstring(transmissions[0], transmissions[1]);

    if (lcs.length() > 0){
        
        std::cout << "Longest Common Substring: " << lcs << std::endl << std::endl;

        // Encontrar las posiciones del substring más largo

        std::vector<std::pair<int,int>> positions1 = longestCommonSubstringPositions(transmissions[0], transmissions[1]);
        std::vector<std::pair<int,int>> positions2 = longestCommonSubstringPositions(transmissions[1], transmissions[0]);

        std::cout << "T R A N S M I S S I O N 1" << std::endl << std::endl;

        for (int i = 0; i < positions1.size(); i++){
            std::cout << "(" << positions1[i].first << ", " << positions1[i].second << ")" << std::endl;
        }

        std::cout << "\nT R A N S M I S S I O N 2" << std::endl << std::endl;

        for (int i = 0; i < positions2.size(); i++){
            std::cout << "(" << positions2[i].first << ", " << positions2[i].second << ")" << std::endl;
        }

    } else {
        std::cout << "No common substring found" << std::endl;
    }

    std::cout << "Mirror code in transmissions: " << std::endl;
    for (int i = 0; i < transmissions.size(); i++){
        pair<int, int> res = manacher(transmissions[i]);
        std::cout << "Positions of longest mirror code in transmission \n" << transmissions[i] << ": " << res.first << " " << res.second << std::endl;

        std::cout << "Longest mirror code: " << transmissions[i].substr(res.first - 1, res.second - res.first + 1) << std::endl;
        std::cout << std::endl;
    }

    return 0;
}