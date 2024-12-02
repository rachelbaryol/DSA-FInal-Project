#ifndef FILEREADER_H
#define FILEREADER_H
#include <fstream>
#include <sstream>
#include <vector>
#include "Node.h"
using namespace std;

class FileReader {
private:
    Node* Deserialize(istringstream& stream);

public:
    vector<Node*> ReadFile(string file);
};



#endif //FILEREADER_H
