#ifndef NODE_H
#define NODE_H
#include <string>
using namespace std;


class Node {
private:
    int _year;
    int _month;
    int _day;
    int _hour;
    int _minute;
    float _temp;
    float _dewpoint;
    float _pressure;
    float _windSpeed;

public:
    Node(int yr, int month, int day, int hour, int minute, float temp, float dew, float pres, float windSpeed);
};



#endif //NODE_H
