#include <bits/stdc++.h>
using namespace std;

struct  Node
{
	int data;
	Node* next;
};

void Insert(Node** head, int data, int pos) {

	Node* temp1 = new Node();
	temp1 -> data = data ;
	temp1 -> next = NULL;

	if (pos == 1) {
		temp1 -> next = *head;
		*head = temp1 ;
		return;
	}

	Node* temp2 = *head;
	for (int i = 0; i < pos - 2; ++i)
	{
		temp2 =  temp2 ->next ;
	}

	temp1 -> next = temp2 -> next ;
	temp2 ->next = temp1;
}

void Print(Node* head) {
	Node* temp = head;
	while (temp != NULL) {
		cout << temp -> data << " ";
		temp = temp->next;
	}
	cout << endl;
}


int main(int argc, char const *argv[])
{

	Node* head = NULL; //empty list

	Insert(&head , 5 , 1);
	Insert(&head , 6 , 2);
	Insert(&head , 8 , 2);
	Print(head);

	return 0;
}