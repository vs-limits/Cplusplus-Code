//#include<iostream>
//using namespace std;
//
//struct Node {
//    char data;
//    Node* left;
//    Node* right;
//    Node(char val) : data(val), left(nullptr), right(nullptr) {}
//};
//
//Node* CreateBST(char arr[], int index, int n) {
//    if (index >= n || arr[index] == '0') {
//        return nullptr;
//    }
//
//    Node* root = new Node(arr[index]);
//    root->left = CreateBST(arr, 2 * index + 1, n);
//    root->right = CreateBST(arr, 2 * index + 2, n);
//
//    return root;
//}
//
//int postOrder(Node* root) {
//    if (root == nullptr) {
//        return 0;
//    }
//
//    int leftHeight = postOrder(root->left);
//    int rightHeight = postOrder(root->right);
//
//    int balance = leftHeight - rightHeight;
//
//    cout << root->data << " " << balance << endl;
//
//    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
//}
//
//int main() {
//    int t;
//    cin >> t;
//
//    while (t--) {
//        int n;
//        cin >> n;
//        char* arr = new char[n];
//        for (int i = 0; i < n; i++) {
//            cin >> arr[i];
//        }
//        Node* root = CreateBST(arr, 0, n);
//        postOrder(root);
//        delete[] arr;
//    }
//}