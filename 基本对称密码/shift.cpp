#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    getline(cin,str);
    int key;
    cin >> key;
    for(int i = 0;i < str.length();i++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            str[i] = (str[i] -'a' + key) % 26 + 'a'; 
        }else if(str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = (str[i] -'A' + key) % 26 + 'A';
        }
    }
    cout << str << endl;
}