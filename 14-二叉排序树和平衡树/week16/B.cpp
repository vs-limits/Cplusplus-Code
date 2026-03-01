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
//		while (num--) {
//			cin >> val;
//			CreateBST(root, val);
//		}
//		InOrder(root);
//		cout << endl;
//
//		int insert_num;
//		cin >> insert_num;
//		while (insert_num--) {
//			int in;
//			cin >> in;
//			CreateBST(root, in);
//			InOrder(root);
//			cout << endl;
//		}
//	}
//}