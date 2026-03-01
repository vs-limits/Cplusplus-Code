//#include<iostream>
//#include<cmath>
//#include<iomanip>
//using namespace std;
//int main() {
//	int n;
//	cin >> n;
//	while (n--) {
//		double x;
//		cin >> x;
//		double root = x / 2;
//		double upper = x;
//		double lower = 0;
//		while (abs(x - pow(root, 2)) > 0.0001) {
//			if(pow(root, 2) > x) {
//				upper = root;
//				root = (lower + root) / 2;
//			} else {
//				lower = root;
//				root = (upper + root) / 2;
//			}
//		}
//		cout << fixed << setprecision(3) << root << endl;
//	}
//}