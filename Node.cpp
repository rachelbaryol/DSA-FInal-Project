//
// Created by rache on 11/28/2024.
//

#include "Node.h"
using namespace std;

Node::Node(int yr, int month, int day, int hour, int minute, float temp, float dew, float pres, float windSpeed) {
    _year = yr;
    _month = month;
    _day = day;
    _hour = hour;
    _minute = minute;
    _temp = temp;
    _dewpoint = dew;
    _pressure = pres;
    _windSpeed = windSpeed;
}
