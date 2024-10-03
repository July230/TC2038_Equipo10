#ifndef READ_FILE
#define READ_FILE

#include "header.h"

std::string readFile(std::string& prefix, std::string& filename){
    std::fstream newfile;
    std::string read;
    std::string str;
    // std::vector<std::string> tempArr;
        
    newfile.open(prefix + filename + ".txt",std::ios::in); // Open file object to read
    if (newfile.is_open()){
        // while(getline(newfile, str)){
        //     tempArr.push_back(str);
        //     tempArr.push_back("\n");
        // }
        while(getline(newfile,read)){
            str += read;
        }
        newfile.close(); // Close file object
    }

    // // Remove last element of array which is newline
    // if (!tempArr.empty() && tempArr.back() == "\n"){
    //     tempArr.pop_back();
    // }
    
    return str;
}

#endif