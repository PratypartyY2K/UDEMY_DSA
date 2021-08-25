/*
1. Define a recursion function that accepts the stack s and an integer as parameters and returns a stack.
2. Base case to be considered is if the stack is empty. For this scenario, push data into the stack and return it.
3. Otherwise, remove the top element of s and store it in a variable, say temp.
4. Recurse again using the new stack
5. Push temp into s.
*/

#include<iostream>
#include<stack>
using namespace std;

//Challenge: Insert at Stack Bottom
void insertAtBottom(stack<int> &s, int data){

	if(s.empty()){
		s.push(data);
		return;
	}
	//rec case
	int temp = s.top();
	s.pop();

	insertAtBottom(s,data);
	s.push(temp);
}

//Challenge : Reverse the Stack
void reverse(stack<int> &s){

	if(s.empty()){
		return;
	}

	int t = s.top();
	s.pop();
	reverse(s);
	insertAtBottom(s,t);
}


int main(){


	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);

	//insertAtBottom(s,5);
	reverse(s);

	while(!s.empty()){
		cout<< s.top() <<endl;
		s.pop();
	}

return 0;
}