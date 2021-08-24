/*
Implement a function that returns the Kth last of element from the linked list, in a single pass. You can assume K will be less than or equal to length of linked list

Input
-----
You will get head of the linked list
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7
K = 3

Output
------
5
*/

#include<bits/stdc++.h>
using namespace std;


class node{
public:
	int data;
	node* next;

	node(int data){
		this->data = data;
		next = NULL;
	}
};

int kthLastElement(node *head, int k){
    //Complete this function to return kth last element
    node *slow=head;
    node *fast=head;
    for(int i = 0; i < k; i++) {
        fast = fast->next;
    }
    
    while(fast!=NULL) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow->data;    
}