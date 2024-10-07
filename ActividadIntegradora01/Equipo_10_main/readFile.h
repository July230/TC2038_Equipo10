#ifndef READ_FILE
#define READ_FILE

#include "header.h"

std::string readFile(std::string& prefix, std::string& filename){
    std::fstream newfile;
    std::string read;
    std::string str;
        
    newfile.open(prefix + filename + ".txt",std::ios::in); // Open file object to read
    if (newfile.is_open()){
        while(getline(newfile,read)){
            str += read;
        }
        newfile.close(); // Close file object
    }
    
    return str;
}

#endif