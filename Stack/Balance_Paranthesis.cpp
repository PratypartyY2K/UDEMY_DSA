/*
Solution:
    scan from left to right
    if opening symbol, add it to a list
    if closing symbol, remove last opening symbol in list
*/
/*
for i <- 0 to n-1 {
    if exp[i] is '(' or '{' or '['
        push(exp[i])
    else if exp[i] is ')' or '}' or ']' {
        if(S is empty) || (top does not pair with exp[i]) {
            return false
        }
        else {
            pop()
        }
    }
}
return S is empty ? true : false
*/
#include <iostream>
#include <string>
#include <stack>

using namespace std;

/* Function to check whether two charachters are opening
    and closing of the same type*/
bool arePair(char opening, char closing) {
    if(opening == '(' && closing == ')') return true;
    else if(opening == '{' && closing == '}') return true;
    else if(opening == ']' && closing == ']') return true;
    return false;
}

bool areParanthesisBalanced(string exp) {
    stack<char> S;
    for(int i = 0; i < exp.length(); i++) {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            S.push(exp[i]);
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if(S.empty() || !arePair(S.top(), exp[i]))
                return false;
            else
                return true;
            
        }
    }
    return S.empty() ? true : false;
}

int main() {
    string expression;
    cout << "Enter an expression";
    cin >> expression;
    if(areParanthesisBalanced(expression))
        cout << "Balanced\n";
    else
        cout << "Not Balanced\n";
    return 0;
}
