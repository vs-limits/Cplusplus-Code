//#include<iostream>
//using namespace std;
//template<class T>
//void sort(T *arr,int len) {
//	for (int i = 0; i < len; i++) {
//		for (int j = i + 1; j < len; j++) {
//			if (arr[i] < arr[j]) {
//				int temp = arr[i];
//				arr[i] = arr[j];
//				arr[j] = temp;
//			}
//		}
//	}
//}
//
//int main()
//{
//	char arr1[] = "badefc";
//	int arr2[] = { 7,5,8,4,3,9,1,2,6 };
//	int num = sizeof(arr1) / sizeof(char);
//	int num2 = sizeof(arr2) / sizeof(int);
//	sort(arr1, num);
//	for (int i = 0; i < num; i++) {
//		cout << arr1[i];
//	}
//	cout << endl;
//	sort(arr2, num2);
//	for (int i = 0; i < num2; i++) {
//		cout << arr2[i];
//	}
//	cout << endl;
//	return 0;
//}