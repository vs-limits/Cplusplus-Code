//#include<iostream>
//using namespace std;
//
//template<class T>
//T Max(T *arr, int len) {
//	/*return *max_element(arr, arr + len);*/
//	T max = arr[0];
//	for (int i = 0; i < len; i++) {
//		if (max < arr[i]) {
//			max = arr[i];
//		}
//	}
//	return max;
//}
//
//template<class T>
//class cryption {
//protected:
//	T clear[100];
//	T secret[100];
//	T key;
//	int len;
//public:
//	cryption(T k, T* c, int l) {
//		key = k;
//		len = l;
//		for (int i = 0; i < len; i++) {
//			clear[i] = c[i];
//		}
//		for (int i = 0; i < len; i++) {
//			secret[i] = 0;
//		}
//	}
//	void encrypt() {
//		T t_m = Max(clear, len);
//		for (int i = 0; i < len; i++) {
//			clear[i] = t_m - clear[i];
//		}
//		for (int i = 0; i < len; i++) {
//			secret[i] = clear[i] + key;
//		}
//	}
//	void print(){
//		int i;
//		for (i = 0; i < len - 1; i++)
//		{
//			cout << secret[i] << " ";
//		}
//		cout << secret[i] << endl;
//	}
//};
//
//int main()
//{
//	int len;
//	int ik, ic[100];
//	double dk, dc[100];
//	char ck, cc[100];
//	cin >> ik >> len;
//	for (int i = 0; i < len; i++) {
//		cin >> ic[i];
//	}
//	cryption<int> icode(ik, ic, len);
//	icode.encrypt();
//	icode.print();
//	cin >> dk >> len;
//	for (int i = 0; i < len; i++)
//	{
//		cin >> dc[i];
//	}
//	cryption<double> dcode(dk, dc, len);
//	dcode.encrypt();
//	dcode.print();
//	cin >> ck >> len;
//	for (int i = 0; i < len; i++)
//	{
//		cin >> cc[i];
//	}
//	cryption<char> ccode(ck, cc, len);
//	ccode.encrypt();
//	ccode.print();
//	return 0;
//}