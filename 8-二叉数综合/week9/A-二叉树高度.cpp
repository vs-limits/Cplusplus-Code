#include<iostream>
#include<cmath>
using namespace std;

struct TreeNode {
	char data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(char value) { data = value; left = NULL; right = NULL; }
};

void createBiTree(TreeNode*& root) {
	char value;
	cin >> value;
	if (value == '0') {
		root = NULL;
		return;
	}
	root = new TreeNode(value);
	createBiTree(root->left);
	createBiTree(root->right);
}

int TreeHigh(TreeNode*& root) {
	if (root == NULL) return 0;
	int high = max(TreeHigh(root->left), TreeHigh(root->right)) + 1;
	return high;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		TreeNode* root = NULL;
		createBiTree(root);
		cout << TreeHigh(root) << endl;;
	}
}