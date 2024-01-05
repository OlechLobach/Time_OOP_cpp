#include "Time.h"

Time::Time() : hours(0), minutes(0), seconds(0) {}

Time::Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

Time Time::operator++() {
    seconds++;
    if (seconds >= 60) {
        seconds -= 60;
        minutes++;
        if (minutes >= 60) {
            minutes -= 60;
            hours = (hours + 1) % 24;
        }
    }
    return *this;
}

Time Time::operator--() {
    seconds--;
    if (seconds < 0) {
        seconds += 60;
        minutes--;
        if (minutes < 0) {
            minutes += 60;
            hours = (hours - 1 + 24) % 24;
        }
    }
    return *this;
}

bool Time::operator==(const Time& other) const {
    return hours == other.hours && minutes == other.minutes && seconds == other.seconds;
}

bool Time::operator!=(const Time& other) const {
    return !(*this == other);
}

bool Time::operator>(const Time& other) const {
    if (hours != other.hours) return hours > other.hours;
    if (minutes != other.minutes) return minutes > other.minutes;
    return seconds > other.seconds;
}

bool Time::operator<(const Time& other) const {
    return !(*this > other || *this == other);
}

Time& Time::operator+=(int secondsToAdd) {
    for (int i = 0; i < secondsToAdd; ++i) {
        ++(*this);
    }
    return *this;
}

Time& Time::operator-=(int secondsToSubtract) {
    for (int i = 0; i < secondsToSubtract; ++i) {
        --(*this);
    }
    return *this;
}

ostream& operator<<(ostream& os, const Time& time) {
    os << time.hours << "h " << time.minutes << "m " << time.seconds << "s";
    return os;
}

istream& operator>>(istream& is, Time& time) {
    is >> time.hours >> time.minutes >> time.seconds;
    return is;
}