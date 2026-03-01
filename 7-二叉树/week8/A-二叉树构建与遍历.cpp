#include<iostream>
using namespace std;

struct TreeNode {
	char data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(char value) {
		data = value;
		left = NULL;
		right = NULL;
	}
};

void CreateBinaryTree(TreeNode* &root) {
	char value;
	cin >> value;
	if (value == '#') {
		root = NULL;
		return;
	}
	root = new TreeNode(value);
	CreateBinaryTree(root->left);
	CreateBinaryTree(root->right);
}

void preOrder(TreeNode*& root) {
	if (root == NULL) return;
	cout << root->data;
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(TreeNode*& root) {
	if (root == NULL) return;
	inOrder(root->left);
	cout << root->data;
	inOrder(root->right);
}

void postOrder(TreeNode*& root) {
	if (root == NULL) return;
	postOrder(root->left);
	postOrder(root->right);
	cout << root->data;
}

int main() 
{
	int t;
	cin >> t;
	while (t--) {
		TreeNode* T = NULL;
		CreateBinaryTree(T);
		preOrder(T);
		cout << endl;
		inOrder(T);
		cout << endl;
		postOrder(T);
		cout << endl;
	}
}