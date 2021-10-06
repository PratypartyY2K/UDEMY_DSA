#include <iostream>
#include <stack>
#include <string.h>

using namespace std;

// Function to evaluate Postfix expression and return output
int evaluatePostfix(string expresion);

// Function to perform an operation and return output
int performOperation(char operation, int operand1, int operand2);

// Function to verify whether a character is operator symbol or not
bool isOperator(char C);

// Function to verify whther a character is numeric digit
bool isNumericDigit(char C);

int main() {
    string expression;
    cout << "Enter Postfix Experssion \n";
    getline(cin, expression);
    int result = evaluatePostfix(expression);
    cout << "Output = " << result << "\n";
    return 0;
}

bool isNumericDigit(char C) {
    if(C >= '0' && C <= '9')
        return true;
    
    return false;
}

bool isOperator(char C) {
    if (C == '+' || C == '-' || C == '*' || C == '/')
        return true;
    
    return false;    
}

int performOperation(char operation, int operand1, int operand2) {
    
    if(operation == '+') 
        return operand1 + operand2;
    
    else if(operation == '-') 
        return abs(operand1 - operand2);
    
    else if(operation == '*') 
        return operand1 * operand2;
    
    else if(operation == '/') 
        return operand1 / operand2;

    else
        cout << "Unexpected Error \n";
    
    return -1;   
}

int evaluatePostfix(string expression) {
    stack<int> S;

    for(int i = 0;i < expression.length(); i++) {

        // Scanning each character from left to right
        // If character is a delimiter, move on
        if(expression[i] == ' ' || expression[i] == ',')
            continue;
        
        // If character is operator, pop two elements from stack, perform
        // operation and push the result back
        else if(isOperator(expression[i])) {
            // Pop two operands
            int operand1 = S.top(); S.pop();
            int operand2 = S.top(); S.pop();
            //Perform operation
            int result = performOperation(expression[i], operand1, operand2);
            //Push back result of operation on stack
            S.push(result);
        }

        else if(isNumericDigit(expression[i])) {
            // Extract the numeric operand from the string
			// Keep incrementing i as long as you are getting a numeric digit. 
			int operand = 0; 
			while(i<expression.length() && isNumericDigit(expression[i])) {
				// For a number with more than one digits, as we are scanning from left to right. 
				// Everytime , we get a digit towards right, we can multiply current total in operand by 10 
				// and add the new digit. 
				operand = (operand*10) + (expression[i] - '0'); 
				i++;
			}
			// Finally, you will come out of while loop with i set to a non-numeric character or end of string
			// decrement i because it will be incremented in increment section of loop once again. 
			// We do not want to skip the non-numeric character by incrementing i twice. 
			i--;

			// Push operand on stack. 
			S.push(operand);
		}
	}
	// If expression is in correct format, Stack will finally have one element. This will be the output. 
    return S.top();     
    
}