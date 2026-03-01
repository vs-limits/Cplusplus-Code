#include<iostream>
using namespace std;

struct treenode {
	char data;
	treenode* left;
	treenode* right;
	treenode* father;
	treenode(char value) { data = value; left = NULL; right = NULL; father = NULL; }
};

void CreateTree(treenode*& root,treenode* father) {
	char value;
	cin >> value;
	if (value == '0') {
		root = NULL;
		father = father;
		return;
	}
	root = new treenode(value);
	root->father = father;
	CreateTree(root->left,root);
	CreateTree(root->right,root);
	
}

int leftleadcount(treenode*& root) {
	if (root == NULL) return 0;
	if (root->left == NULL && root->right == NULL && root->father && root->father->left == root) {
		return 1;
	}
	else {
		return leftleadcount(root->left) + leftleadcount(root->right);
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		treenode* T = NULL;
		CreateTree(T,NULL);
		int count = leftleadcount(T);
		cout << count << endl;
	}
}