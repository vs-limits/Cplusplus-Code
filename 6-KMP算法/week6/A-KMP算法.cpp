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
        int i = 0,j = -1;
        int len = p.length();
        while (i < len - 1) {
            if (j == -1 || p[i] == p[j]) {
                cout << p[i] << " " << p[j];
                i++;
                j++;
                next[i] = j;
            }
            else {
                j = next[j];
            }
        }
    }
    int KMPFind(string p,int pos,int next[]){
        int i = pos,int j = 0,len = p.length();
        while(i < size && j < len){
            if(j == -1 || mainstr[i] == p[j]){
                i++;
                j++;
            }else{
                j = next[j];
            }
        }
        if(j == len){
            return i - j + 1;
        }else{
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
    for (i = 0; i < L; i++)
        cout << next[i] << ' ';
    cout << endl;
    int v = -1;
    v = KMPFind(p, pos, next);
    delete[]next;
    return v;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;//����
        string p;//Ŀ�괮
		int pos = 0;//��ʼλ��
        cin >> s >> p;
        myString ms;
        ms.SetVal(s);
        int res = ms.KMPFindSubstr(p, pos);
        cout << res << endl;
    }
}