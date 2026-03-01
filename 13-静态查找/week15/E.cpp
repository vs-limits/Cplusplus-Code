//#include <iostream>
//#include <string>
//using namespace std;
//
//int main() {
//    int t;
//    cin >> t;
//    while (t--) {
//        string str;
//        char target;
//        cin >> str >> target;
//
//        int left = 0;
//        int right = str.length() - 1;
//        while (left <= right) {
//            int mid = left + (right - left) / 2;
//            if (str[mid] <= target) {
//                left = mid + 1;
//            }
//            else {
//                right = mid - 1;
//            }
//        }
//
//        char ans = (left < str.length()) ? str[left] : str[0];
//        cout << ans << endl;
//    }
//    return 0;
//}