#include <iostream>
#include "Node.h"

Node::Node(int yr, int month, int day, int hour, int minute, float temp, float dew) {
    _year = yr;
    _month = month;
    _day = day;
    _hour = hour;
    _minute = minute;
    _temp = temp;
    _dewpoint = dew;
}

float Node::getTemp() const {
    return _temp;
}

void Node::PrintNode() const {
    cout << _month << "-" << _day << "-" << _year << " at " << _hour << ":" << _minute << " | Temperature: "
        << _temp << " | Dewpoint: " << _dewpoint << endl;
}
