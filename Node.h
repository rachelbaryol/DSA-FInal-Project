#ifndef NODE_H
#define NODE_H

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

public:
    Node(int yr, int month, int day, int hour, int minute, float temp, float dew);
    float getTemp() const;
    void PrintNode() const;
};



#endif //NODE_H
