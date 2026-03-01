//#include<iostream>
//#include<iomanip>
//using namespace std;
//
//class CVector {
//private:
//	int* score;
//	int n;
//public:
//	CVector() {
//		n = 5;
//		score = new int[n];
//		for (int i = 0; i < n; i++) {
//			score[i] = i;
//		}
//	}
//	CVector(int nn, int* s) {
//		n = nn;
//		score = new int[n];
//		for (int i = 0; i < n; i++) {
//			score[i] = s[i];
//		}
//	}
//	float Average(){
//		float ave,sum = 0;
//		for (int i = 0; i < n; i++) {
//			sum += score[i];
//		}
//		ave = sum / n;
//		return ave;
//	}
//	void display() {
//		for (int i = 0; i < n; i++) {
//			cout << score[i] << " ";
//		}
//	}
//};
//
//class Student {
//private:
//	string name;
//	CVector score;
//public:
//	Student() {
//		name = "";
//	}
//	Student(string name1, int n, int* s) :name(name1), score(n, s) {};
//	void show() {
//		cout << name << " ";
//		score.display();
//		cout << fixed << setprecision(2) << score.Average() << endl;
//	}
//};
//
//int main()
//{
//	string name;
//	int n;
//	while (cin >> name) {
//		cin >> n;
//		int* s = new int[n];
//		for (int i = 0; i < n; i++) {
//			cin >> s[i];
//		}
//		Student obj(name, n, s);
//		obj.show();
//	}
//	return 0;
//}