#include <iostream>
using namespace std;

#define MAX_SIZE 101

class Stack {
    private:
        int A[MAX_SIZE]; //aray to store the stack
        int top; //variable to mark the top index of stack
    
    public:
        //constructor
        Stack() {
            top = -1; // for empty array, set top = -1
        }

        //Push operation to insert an element on top of stack
        void Push (int x) {
            if (top == MAX_SIZE - 1) {
                //overflow case
                cout << "Error: stack overflow\n";
                return;
            }
            A[++top] = x;
        }

        // Pop operation to remove an element from top of stack
        void Pop() {
            if (top == -1) {
                // If Stack is empty, pop should throw error
                cout << "Error: Stack underflow; No element to pop\n";
                return;
            }
            cout << "Element popped: " << A[top];
            top--;
        }

        // Top operation to return element at top of stack
        int Top() {
            return A[top];
        }

        //This function will return 1 (true) if stack is empty, 0 (false) otherwise
        int IsEmpty() {
            if (top == -1) return -1;
            return 0;
        }

        void Print() {
            int i;
            printf("Stack: ");
            for(i = 0; i <= top; i++) 
                cout << A[i] << " ";
            cout << "\n";
        }
};

int main() {
    Stack S;
    int choice, ele;
    cout << "Welcome to Stack Implementation using Arrays!!\n";
    cout << "1.Push an element to the Stack\n2.Pop an element from the Stack\n3.Peek at top element of Stack\n4.Check whether Stack is empty\n";
    do
    {
        cout << "Enter your choice";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the element to be pushed into the stack";
            cin >> ele;
            S.Push(ele);
            S.Print();
            break;
        case 2:
            cout << "Pop element from Stack\n";
            S.Pop();
            break;
        case 3:
            cout << "Peek at the top element";
            S.Top();
        case 4:
            if (S.IsEmpty())
                cout << "Stack is emmpty";
            else
                cout << "Stack is not empty";
            break;        
        default:
            break;
        }
    } while (choice < 5);
    return 0;
}