#include "header.h"
#include "readFile.h"
#include "palindromo.h"

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

    std::cout << "Transmissions:" << std::endl;
    for (int i = 0; i < transmissions.size(); i++){
        for (int j = 0; j < transmissions[i].length(); j++){
            std::cout << transmissions[i][j];
        }
        std::cout << "\n" << std::endl;
    }

    std::cout << "Malicious Code:" << std::endl;
    for (int i = 0; i < patterns.size(); i++){
        for (int j = 0; j < patterns[i].length(); j++){
            std::cout << patterns[i][j];
        }
        std::cout << std::endl;
    }

    std::cout << "Mirror code in transmissions: " << std::endl;
    for (int i = 0; i < transmissions.size(); i++){
        pair<int, int> res = manacher(transmissions[i]);
        std::cout << "Posiciones del palindromo mas largo: " << res.first << " " << res.second << std::endl;

        std::cout << "Palindromo mas largo: " << transmissions[i].substr(res.first, res.second - res.first + 1) << std::endl;
        std::cout << std::endl;
    }
    
    return 0;
}