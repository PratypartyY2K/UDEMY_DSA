#include <iostream>
#include <string>
using namespace std;

string convert_to_digital_time(int minutes){
    //complete this function
    int hr, min; string res;
    hr = minutes / 60; // get the hour 
    min = minutes % 60; // get the minutes
    if (hr < 10 or min < 10)
        res = '0' + to_string(hr) + ":" + '0' + to_string(min);
    else
        res = to_string(hr) + ":" + to_string(min);
    return res;
}

int main() {
    
    int input; // 1180
    cin >> input;
    string result;
    result = convert_to_digital_time(input);
    cout << result << endl;

    return 0;
}