#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node* next;	
		
};

Node* head;
void Insert(int data, int n){
	Node* temp1 = new Node();
	temp1 -> data = data;
	temp1 -> next = NULL;
	if (n==1)
	{
		temp1 -> next = head;
		head =temp1;
		return;
	}

	Node* temp2 = head;
	for (int i = 0; i < n-2; i++)
	{
		temp2 = temp2 -> next; 
	}

	temp1 -> next = temp2 -> next;
	temp2 -> next = temp1;

	
}

void Print() {
	cout << "List is : ";
	Node* temp = head ;
	while(temp != NULL){
		cout << temp -> data << " ";
		temp = temp -> next;
	}

	cout << endl;

}

void Delete(int n){
	Node* temp1 =head;
	if (n==1)
	{
		head = temp1 -> next;
		delete temp1;
		return;
	}


	int i;
	for (int i = 0; i < n-2; ++i)
	{
		temp1=temp1 -> next ;  //temp1 points to n-1 th Node
	}

	Node* temp2 =temp1 -> next;   //nth node

	temp1 -> next = temp2 -> next;  // n+1 th node 
	delete (temp2);
}


int main(int argc, char const *argv[])
{
	head = NULL; 
	Insert(1,1);
	Insert(2,2);
	Insert(3,1);
	Insert(4,2);
	Insert(7,4);
	Insert(8,3);
	Insert(4,5);
	Print();
	Delete(4);
	Print();
	return 0;
}