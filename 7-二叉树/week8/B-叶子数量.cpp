#include<iostream>
using namespace std;

struct treenode {
	char data;
	treenode* left;
	treenode* right;
	treenode(char value) { data = value; left = NULL; right = NULL; }
};

void CreateTree(treenode* &root) {
	char value;
	cin >> value;
	if (value == '0') {
		root = NULL;
		return;
	}
	root = new treenode(value);
	CreateTree(root->left);
	CreateTree(root->right);
}

int leadcount(treenode* &root) {
	if (root == NULL) return 0;
	if (root->left == NULL && root->right == NULL) {
		return 1;
	}
	else {
		return leadcount(root->left) + leadcount(root->right);
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		treenode* T = NULL;
		CreateTree(T);
		int count = leadcount(T);
		cout << count << endl;
	}
}