#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class myString {
private:
  string mainstr;
  int size;       
  void GetNext(string p, int next[]) {
      next[0] = -1;
      int i = 0, j = -1;
      int len = p.length();
      while (i < len) {
          if (j == -1 || p[i] == p[j]) {
              i++;
              j++;
              next[i] = j;
          }
          else {
              j = next[j];
          }
      }
  }
  int KMPFind(string p, int pos, int next[]) {
      int i = pos, j = 0, len = p.length();
      while (i < size && j < len) {
          if (j == -1 || mainstr[i] == p[j]) {
              i++;
              j++;
          }
          else {
              j = next[j];
          }
      }
      if (j == len) {
          return i - j + 1;
      }
      else {
          return 0;
      }
  }
public:
  myString();
  ~myString();
  void SetVal(string sp);
  int KMPFindSubstr(string p, int pos);
  int cycle(string str);
};

myString::myString() {
  size = 0;
  mainstr = "";
}

myString::~myString() {
  size = 0;
  mainstr = "";
}

void myString::SetVal(string sp) {
  mainstr = "";
  mainstr.assign(sp);
  size = mainstr.length();
}

int myString::KMPFindSubstr(string p, int pos) {
  int L = p.length();
  int* next = new int[L];
  GetNext(p, next);
  int v = KMPFind(p, pos, next);
  delete[] next;
  return v;
}

int myString::cycle(string str) {
	int len = str.length();
  int* next = new int[len + 1];
  int res = 0;
  GetNext(str, next);
  int max = -1;
  for (int k = 0; k < len + 1; k++) {
      if (next[k] > max) {
          max = next[k];
      }
  }
  int cycle_len = len - max;
  if (max == 0) {
      res = cycle_len;
      return res;
  }
  else {
      int leave = len % cycle_len;
      if (leave == 0) {
          return res;
      }
      else {
          res = cycle_len - leave;
          return res;
      }
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
      string s;
      cin >> s;
      myString ms;
      ms.SetVal(s);
      int result = ms.cycle(s);
      cout << result << endl;
  }
  return 0;
}