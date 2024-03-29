#ifndef TIME_H
#define TIME_H

#include <iostream>
using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time();
    Time(int h, int m, int s);

    Time operator++();
    Time operator--();

    bool operator==(const Time& other) const;
    bool operator!=(const Time& other) const;
    bool operator>(const Time& other) const;
    bool operator<(const Time& other) const;

    Time& operator+=(int secondsToAdd);
    Time& operator-=(int secondsToSubtract);

    friend ostream& operator<<(ostream& os, const Time& time);
    friend istream& operator>>(istream& is, Time& time);
};

#endif
