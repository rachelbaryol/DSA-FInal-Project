#include <fstream>
#include <iostream>
#include <sstream>
#include "FileReader.h"

#include "Node.h"
using namespace std;

void FileReader::ReadFile(string file) {
    // Reads data from psv file and establishes a Node
    ifstream csv(file);
    string line;
    getline(csv, line);

    while (getline(csv, line)) {
        if (line != "") {
            istringstream stream(line);
            Deserialize(stream);
        }
    }
}

void FileReader::Deserialize(istringstream& stream) {
    // Receives stream from file and turns data into Node object
    int yr, month, day, hour, minute;
    float temp, dewPoint, pressure, windSpeed;
    string token;

    // Discard Station ID and name
    getline(stream, token, '|');
    getline(stream, token, '|');

    // Time info
    getline(stream, token, '|');
    try {
        yr = stoi(token);
    }
    catch (invalid_argument) {
        yr = 0;
    }

    getline(stream, token, '|');
    try {
        month = stoi(token);
    }
    catch (invalid_argument) {
        month= 0;
    }

    getline(stream, token, '|');
    try {
        day = stod(token);
    }
    catch (invalid_argument) {
        day = 0;
    }

    getline(stream, token, '|');
    try {
        hour = stod(token);
    }
    catch (invalid_argument) {
        hour = 0;
    }

    getline(stream, token, '|');
    try {
        minute = stod(token);
    }
    catch (invalid_argument) {
        minute = 0;
    }

    // Discard location info
    getline(stream, token, '|');
    getline(stream, token, '|');
    getline(stream, token, '|');

    // Temperature
    getline(stream, token, '|');
    try {
        temp = stof(token);
    }
    catch (invalid_argument) {
        temp = 0.0;
    }

    // Discard temperature source info
    getline(stream, token, '|');
    getline(stream, token, '|');
    getline(stream, token, '|');
    getline(stream, token, '|');
    getline(stream, token, '|');

    // Dew Point
    getline(stream, token, '|');
    try {
        dewPoint = stof(token);
    }
    catch (invalid_argument) {
        dewPoint = 0.0;
    }

    // Discard dew point source info
    getline(stream, token, '|');
    getline(stream, token, '|');
    getline(stream, token, '|');
    getline(stream, token, '|');
    getline(stream, token, '|');

    // Pressure
    getline(stream, token, '|');
    try {
        pressure = stof(token);
    }
    catch (invalid_argument) {
        pressure = 0.0;
    }

    // Discard pressure source info
    getline(stream, token, '|');
    getline(stream, token, '|');
    getline(stream, token, '|');
    getline(stream, token, '|');
    getline(stream, token, '|');
    getline(stream, token, '|');
    getline(stream, token, '|');
    getline(stream, token, '|');
    getline(stream, token, '|');
    getline(stream, token, '|');
    getline(stream, token, '|');
    getline(stream, token, '|');
    getline(stream, token, '|');
    getline(stream, token, '|');
    getline(stream, token, '|');
    getline(stream, token, '|');

    // Wind speed
    getline(stream, token, '|');
    try {
        windSpeed = stof(token);
    }
    catch (invalid_argument) {
        windSpeed = 0.0;
    }

    Node* node = new Node(yr, month, day, hour, minute, temp, dewPoint, pressure, windSpeed);


}
