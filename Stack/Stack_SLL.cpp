#include <iostream>
using namespace std;

class node
{
	public:
        int data;
	    node *next;
};

class Stack
{
	node *front;  // points to the head of list
	public:
	Stack()
	{
		front = NULL;
	}
	// push method to add data element
	void push(int);
	// pop method to remove data element
	void pop();
	// top method to return top data element
	int top();
};

void Stack :: push(int d)
{
	// creating a new node
	node *temp;
	temp = new node();
	// setting data to it
	temp->data = d;

	// add the node in front of list
	if(front == NULL)
	{
		temp->next = NULL;
	}
	else
	{
		temp->next = front;
	}
    cout << d;
	front = temp;
}

void Stack :: pop()
{
	// if empty
	if(front == NULL)
		cout << "UNDERFLOW\n";
	
	// delete the first element
	else
	{
		node *temp = front;
		front = front->next;
        cout << temp->data;
		delete(temp);
	}
}

int Stack :: top()
{
	return front->data;
}

int main() 
{ 
    Stack S;
  
    S.push(10); cout << " pushed to stack\n";
    S.push(20); cout << " pushed to stack\n";
    S.push(30); cout << " pushed to stack\n";
  
    S.pop(); cout << " popped from stack\n";
  
    cout << "Top element is " << S.top() << endl; 
  
    return 0; 
}