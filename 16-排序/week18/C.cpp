#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
   int min = i;       
   int l = 2 * i + 1;  
   int r = 2 * i + 2;  

   if (l < n && arr[l] < arr[min]) {
       min = l;
   }
   if (r < n && arr[r] < arr[min]) {
       min = r;
   }

   if (min != i) {
       int temp = arr[i];
       arr[i] = arr[min];
       arr[min] = temp;

       heapify(arr, n, min);
   }
}

int main() {
   int n;
   cin >> n;

   int* num = new int[n];
   for (int i = 0; i < n; i++) {
       cin >> num[i];
   }

   for (int i = n / 2 - 1; i >= 0; i--) {
       heapify(num, n, i);
   }

   cout << n;
   for (int i = 0; i < n; i++) {
       cout << " " << num[i];
   }
   cout << endl;

   for (int i = n - 1; i > 0; i--) {
       int temp = num[0];
       num[0] = num[i];
       num[i] = temp;

       heapify(num, i, 0);//������С��

       cout << n;
       for (int j = 0; j < n; j++) {
           cout << " " << num[j];
       }
       cout << endl;
   }

}