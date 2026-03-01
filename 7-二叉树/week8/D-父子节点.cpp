#include<iostream>
using namespace std;

struct treenode {
	char data;
	treenode* left;
	treenode* right;
	treenode* father;
	treenode(char value) { data = value; left = NULL; right = NULL; father = NULL; }
};

void CreateTree(treenode*& root, treenode* father) {
	char value;
	cin >> value;
	if (value == '0') {
		root = NULL;
		father = father;
		return;
	}
	root = new treenode(value);
	root->father = father;
	CreateTree(root->left, root);
	CreateTree(root->right, root);

}

void preOrder(treenode*& root) {
	if (root == NULL) return;
	if (root->left == NULL && root->right == NULL && root->father) {
		cout << root->data << " ";
	}
	else if (root->left == NULL && root->right == NULL && root->father == NULL) {
		cout << root->data << " ";
	}
	preOrder(root->left);
	preOrder(root->right);
}

void fatherOrder(treenode*& root) {
	if (root == NULL) return;
	if (root->left == NULL && root->right == NULL && root->father) {
		cout << root->father->data << " ";
	}
	else if (root->left == NULL && root->right == NULL && root->father == NULL) {
		cout << root->data << " ";
	}
	fatherOrder(root->left);
	fatherOrder(root->right);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		treenode* T = NULL;
		CreateTree(T, NULL);
		preOrder(T);
		cout << endl;
		fatherOrder(T);
		cout << endl;
	}
}