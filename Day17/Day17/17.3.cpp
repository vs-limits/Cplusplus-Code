//#include<iostream>
//using namespace std;
//
//template<class T1>
//void ticket(T1* arr, int len) {
//	int flag = 0;
//	for (int i = 0; i < len - 1; i++) {
//		if (arr[i] > arr[i + 1]) {
//			flag = 1;
//		}
//	}
//	if (flag == 0) {
//		cout << "Valid" << endl;
//	}
//	else if (flag == 1) {
//		cout << "Invalid" << endl;
//	}
//}
//
//int main()
//{
//	char tp;
//	while (cin >> tp) {
//		if (tp == 'i') {
//			int* arr = new int[6];
//			for (int i = 0; i < 6; i++) {
//				cin >> arr[i];
//			}
//			ticket<int>(arr, 6);
//		}
//		else if (tp == 'c') {
//			char* arr = new char[6];
//			for (int i = 0; i < 6; i++) {
//				cin >> arr[i];
//			}
//			ticket<char>(arr, 6);
//		}
//		else if (tp == 'f') {
//			float* arr = new float[6];
//			for (int i = 0; i < 6; i++) {
//				cin >> arr[i];
//			}
//			ticket<float>(arr, 6);
//		}
//	}
//	return 0;
//}