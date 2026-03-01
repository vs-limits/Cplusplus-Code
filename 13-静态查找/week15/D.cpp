#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    int** arr = new int* [m];
    for (int i = 0; i < m; i++) {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int target;
        cin >> target;
        bool found = false;
        int left = 0, right = m * n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int row = mid / n;
            int col = mid % n;
            cout << row << " " << col << endl;
            if (arr[row][col] == target) {
                found = true;
                break;
            }
            else if (arr[row][col] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        if (found == true) cout << "true" << endl;
		else cout << "false" << endl;
    }

    return 0;
}