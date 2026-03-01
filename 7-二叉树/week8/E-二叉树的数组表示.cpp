#include<iostream>
using namespace std;

struct treenode {
	int data;
	treenode* left;
	treenode* right;
	treenode(int value) { data = value; left = NULL; right = NULL;}
};

void CreateTree(treenode*& root,int* arr,int index,int num) {

	if(index > num || arr[index - 1] == 0){
		root = NULL;
		return;
	}
	root = new treenode(arr[index - 1]);
	CreateTree(root->left,arr,2*index,num);
	CreateTree(root->right,arr,2*index + 1,num);
}

void preOrder(treenode*& root) {
	if (root == NULL) return;
	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int num;
		cin >> num;
		int* arr = new int[num];
		for (int i = 0; i < num; i++) {
			cin >> arr[i];
		}
		treenode* T = NULL;
		int index = 1;
		CreateTree(T,arr,index,num);
		preOrder(T);
		cout << endl;
	}
}