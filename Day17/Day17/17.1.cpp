//#include<iostream>
//using namespace std;
//
//template<class T1>
//void search(T1 *arr,T1 key,int len) {
//	int flag = 1;
//	for (int i = 0; i < len; i++) {
//		if (arr[i] == key) {
//			flag = 0;
//			cout << i + 1 << endl;
//		}
//	}
//	if (flag == 1) {
//		cout << '0' << endl;
//	}
//}
//
//int main()
//{
//	int t;
//	cin >> t;
//	char tp;
//	int length;
//	while (t--) {
//		cin >> tp >> length;
//		if (tp == 'I') {
//			int* arr = new int[length];
//			for (int i = 0; i < length; i++) {
//				cin >> arr[i];
//			}
//			int key;
//			cin >> key;
//			search<int>(arr, key,length);
//		}
//		else if (tp == 'D') {
//			double* arr = new double[length];
//			for (int i = 0; i < length; i++) {
//				cin >> arr[i];
//			}
//			double key;
//			cin >> key;
//			search<double>(arr, key, length);
//		}
//		else if (tp == 'C') {
//			char* arr = new char[length];
//			for (int i = 0; i < length; i++) {
//				cin >> arr[i];
//			}
//			char key;
//			cin >> key;
//			search<char>(arr, key, length);
//		}
//		else if (tp == 'S') {
//			string* arr = new string[length];
//			for (int i = 0; i < length; i++) {
//				cin >> arr[i];
//			}
//			string key;
//			cin >> key;
//			search<string>(arr, key, length);
//		}
//	}
//	return 0;
//}