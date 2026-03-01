//#include<iostream>
//#include<cstring>
//using namespace std;
//
//class CTelNumber {
//private:
//public:
//	string phonenumber;
//	CTelNumber() {
//		phonenumber = "";
//	}
//	CTelNumber(string num) {
//		phonenumber = num;
//	}
//	CTelNumber(const CTelNumber& num) {
//		phonenumber = num.phonenumber;
//		if (phonenumber[0] == '2' || phonenumber[0] == '3' || phonenumber[0] == '4') {
//			phonenumber = '8' + num.phonenumber;
//		}
//		else if (phonenumber[0] == '5' || phonenumber[0] == '6' || phonenumber[0] == '7' || phonenumber[0] == '8') {
//			phonenumber = '2' + num.phonenumber;
//		}
//	}
//	void show() {
//		cout << phonenumber << endl;
//	}
//};
//
//int main()
//{
//	int t;
//	cin >> t;
//	int flag = 0;
//	while (t--) {
//		string num;
//		cin >> num;
//		if (num.length() != 7) {
//			cout << "Illegal phone number" << endl;
//		}
//		else if (num.length() == 7) {
//			if (num[0] == '9' || num[0] == '0' || num[0] == '1') {
//				cout << "Illegal phone number" << endl;
//			}
//			else {
//				for (int i = 0; i < num.length(); i++) {
//					flag = 1;
//					if (num[i] < '0' || num[i] > '9') {
//						cout << "Illegal phone number" << endl;
//						flag = 0;
//						break;
//					}
//				}
//				if (flag == 1) {
//					CTelNumber num1(num), num2(num1);
//					num2.show();
//				}
//			}
//		}
//
//	}
//	return 0;
//}