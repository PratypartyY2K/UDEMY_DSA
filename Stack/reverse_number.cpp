#include <bits/stdc++.h>
using namespace std;

int reverse(int n){
	int r, d, num = 0, i=1;
	stack<int> s;
	while(n > 0) {
	    r = n % 10;
	    s.push(r);
	    n /= 10;
	}
	while (!s.empty())
    {
        num = num + (s.top() * i);
        s.pop();
        i = i * 10;
    }
    return num;
}

int main() {
    int number;
    cout << "Enter a number";
    cin >> number;
    int reversed_number = reverse(number);
    cout << reversed_number << endl;
    return 0;
}