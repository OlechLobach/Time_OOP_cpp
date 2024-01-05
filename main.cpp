
#include "Time.h"

int main() {
    Time t1(10, 30, 45);

    cout << "Initial time: " << t1 << endl;

    ++t1;
    cout << "Time after increment: " << t1 << endl;

    --t1;
    cout << "Time after decrement: " << t1 << endl;

    Time t2(10, 30, 45);
    if (t1 == t2) {
        cout << "t1 and t2 are equal" << endl;
    }
    else {
        cout << "t1 and t2 are not equal" << endl;
    }

    cout << "Enter hours, minutes, and seconds: ";
    cin >> t2;
    cout << "You entered: " << t2 << endl;

    return 0;
}