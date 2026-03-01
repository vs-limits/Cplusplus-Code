#include<iostream>
#include<string>
using namespace std;
class myString
{
private:
  string mainstr; // ��
  int size;       // ������
  void GetNext(string p, int next[]) {
      next[0] = -1;
      int i = 0, j = -1;
      int len = p.length();
      while (i < len - 1) {
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
};
myString::myString()
{
  size = 0;
  mainstr = "";
}
myString::~myString()
{
  size = 0;
  mainstr = "";
}
void myString::SetVal(string sp)
{
  mainstr = "";
  mainstr.assign(sp);
  size = mainstr.length();
}
int myString::KMPFindSubstr(string p, int pos)
{
  int i;
  int L = p.length();
  int* next = new int[L];
  GetNext(p, next);
  int v = -1;
  v = KMPFind(p, pos, next);
  delete[]next;
  return v;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
      string str;//����
      string modestr;//ģʽ��
      string replacestr;//�滻��
      int pos = 0;//��ʼλ��
      cin >> str >> modestr >> replacestr;
      cout << str << endl;
      myString ms;
      ms.SetVal(str);
      int samepos = ms.KMPFindSubstr(modestr, pos);//��ͬ����λ��
		int len = modestr.length();
      if (samepos == 0) {
          cout << str << endl;
      }
      else {
          string res = str.substr(0, samepos - 1) + replacestr + str.substr(samepos - 1 + len, str.length());
          cout << res << endl;
      }
  }
}