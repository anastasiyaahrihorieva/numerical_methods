#include "header.h"

void saveToFile(const std::string& filename, const std::string& data) {
    std::ofstream outputFile(filename, std::ios::trunc); 
    outputFile << data; 
    outputFile.close();   
}