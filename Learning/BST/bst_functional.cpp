#include <bits/stdc++.h>
using namespace std;

struct  BstNode  // Node Structure
{
	int data;
	BstNode* left;
	BstNode* right;
};

BstNode* GetNewNode(int data) {
	BstNode* newNode  = new BstNode();
	newNode -> data = data;
	newNode -> left = newNode->right = NULL;
	return newNode;
}

BstNode* Insert(BstNode* root , int data) {

	if (root == NULL) {
		root = GetNewNode(data);
		return root;
	}

	else if (data <= root -> data) {
		root -> left = Insert(root -> left , data);
	}

	else {
		root -> right = Insert(root -> right , data);
	}

	return root;

}

void Inorder(BstNode* root) {
	if (root == NULL) {
		return;
	}
	else {
		Inorder(root -> left);
		cout << root -> data << " " ;
		Inorder(root -> right);
	}
}

void Preorder(BstNode* root) {
	if (root == NULL) {
		return;
	}
	else {
		cout << root -> data << " " ;
		Preorder(root -> left);
		Preorder(root -> right);
	}
}

void Postorder(BstNode* root) {
	if (root == NULL) {
		return;
	}
	else {

		Postorder(root -> left);
		Postorder(root -> right);
		cout << root -> data << " " ;
	}
}

int getHeight(BstNode* root)
{
	if (!root)
		return 0;
	return 1 + max(getHeight(root->left) , getHeight(root->right));
}

bool isBalanced(BstNode* treeNode)
{
	if (!treeNode)
		return false;
	int leftHeight = getHeight(treeNode->left);
	int rightHeight = getHeight(treeNode->right);

	if (abs(leftHeight - rightHeight) > 1)
		return false;
	return true;
}

BstNode* FindMin(BstNode* root)
{
	while (root->left != NULL) root = root->left;
	return root;
}



BstNode* Delete(BstNode* root , int data) {
	if (root == NULL) return root;
	else if (data < root-> data) root -> left = Delete(root->left , data);
	else if (data > root-> data) root -> right = Delete(root->right , data);
	else {

		if (root -> left == NULL && root -> right == NULL) {
			delete root;
			root = NULL;
		}

		else if (root -> left == NULL) {
			BstNode* temp = root;
			root = root -> right;
			delete temp ;

		}

		else if (root -> right == NULL) {
			BstNode* temp = root;
			root = root -> left;
			delete temp ;
		}

		else {
			BstNode* temp = FindMin(root->right);
			root -> data = temp-> data;
			root -> right = Delete (root -> right, temp-> data);

		}



	}

	return root;

}


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	BstNode* root  = NULL;
	root = Insert(root, 15);
	root = Insert(root, 2);
	root = Insert(root, 20);
	root = Insert(root, 3);
	root = Insert(root, 25);
	root = Insert(root, 1);
	root = Insert(root, 17);
	cout << "Balanced : " << isBalanced(root) << endl;
	Inorder(root);
	Delete(root , 1);
	cout << endl;
	Inorder(root);

	cout << endl;
	Preorder(root);
	cout << endl;
	Postorder(root);
	cout << endl;
	cout << "Height is : " << getHeight(root) << endl;
	cout << "Balanced : " << isBalanced(root) << endl;

	return 0;
}

