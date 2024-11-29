#ifndef FILEREADER_H
#define FILEREADER_H
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

class FileReader {
private:
    void Deserialize(istringstream& stream);

public:
    void ReadFile(string file);
};



#endif //FILEREADER_H
