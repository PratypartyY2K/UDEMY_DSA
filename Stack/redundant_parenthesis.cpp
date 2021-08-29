/*
Given a string of balanced expression, find if it contains a refunant parenthesis or not. A set of parenthesis are redundant if same sub-expression is surrounded by unnecessary or multiple brackets. Print 'Yes' if redundant else 'No'.

Input        Output
-----        ------
((a+b))        Yes
(a+(b)/c)      Yes
(a+b*(c-d))    No
*/
#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool checkRedundant(string str){
	//Complete
	stack<char> s;

	for(char ch : str){
		if(ch!=')'){
			s.push(ch); // a,b, + , - , ( ....
		}
		else{
			// ')'
			bool operator_found = false;

			while(!s.empty() and s.top()!='('){
				char top = s.top();
				if(top=='+' or top=='-' or top=='*' or top=='/'){
					operator_found = true;
				}
				s.pop();
			}
			s.pop(); //pop the opening bracked after the loop if over

			if(operator_found == false){
				return true;
			}
		}
	}
	return false;
}


int main() {
    string str = "((a+b)+c) + ((d*e))";
    if(checkRedundant(str)){
        cout<<"Contains Redundant Parenthesis";
    }
    else{
        cout<<"r";
    }
    return 0;
}