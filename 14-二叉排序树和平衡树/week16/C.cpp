//#include<iostream>
//using namespace std;
//
//struct Node {
//	int data;
//	Node* left;
//	Node* right;
//	Node(int val) : data(val), left(nullptr), right(nullptr) {}
//};
//
//void CreateBST(Node*& root, int val) {
//	if (val < root->data) {
//		if (root->left == nullptr) {
//			root->left = new Node(val);
//		}
//		else {
//			CreateBST(root->left, val);
//		}
//	}
//	else {
//		if (root->right == nullptr) {
//			root->right = new Node(val);
//		}
//		else {
//			CreateBST(root->right, val);
//		}
//	}
//}
//
//void InOrder(Node*& root) {
//	if (root == NULL) return;
//	InOrder(root->left);
//	cout << root->data << " ";
//	InOrder(root->right);
//}
//
//Node* findMin(Node* node) {
//	while (node->left != nullptr) {
//		node = node->left;
//	}
//	return node;
//}
//
//void Delete(Node*& root, int del) {
//	if (root == NULL) {
//		return;
//	}
//	if (del < root->data) {
//		Delete(root->left, del);
//	}
//	else if(del > root->data){
//		Delete(root->right, del);
//	}
//	else if (del == root->data) {
//		if (root->left == nullptr && root->right == nullptr) {
//			delete root;
//			root = nullptr;
//		}
//		else if (root->left == nullptr) {
//			Node* temp = root;
//			root = root->right;
//			delete temp;
//		}
//		else if (root->right == nullptr) {
//			Node* temp = root;
//			root = root->left;
//			delete temp;
//		}
//		else {
//			Node* temp = findMin(root->right);
//			root->data = temp->data;
//			Delete(root->right, temp->data);
//		}
//
//	}
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		int num;
//		cin >> num;
//		Node* root = nullptr;
//		int val;
//		cin >> val;
//		num--;
//		root = new Node(val);
//
//		while (num--) {
//			cin >> val;
//			CreateBST(root, val);
//		}
//
//		InOrder(root);
//		cout << endl;
//
//		int delete_num;
//		cin >> delete_num;
//		while (delete_num--) {
//			int del;
//			cin >> del;
//			Delete(root, del);
//			InOrder(root);
//			cout << endl;
//		}
//	}
//}