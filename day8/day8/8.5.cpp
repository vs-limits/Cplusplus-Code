#include<iostream>
using namespace std;

class Account
{
private:
    static float count; // �˻������
    static float interestRate;
    string accno, accname;
    float balance;
public:
    Account(string ac, string na, float ba);
    ~Account() {};
    void deposit(float amount); // ���
    void withdraw(float amount); // ȡ��
    float getBalance(); // ��ȡ�˻����
    void show(); // ��ʾ�˻����л�����Ϣ
    static float getCount() {
        return count;
    }; // ��ȡ�˻������
    static void setInterestRate(float rate) {
        interestRate = rate;
    }; 
    static float getInterestRate() {
        return interestRate;
    }; // ��ȡ����
};
float Account::count = 0;
float Account::interestRate = 0;

Account::Account(string ac, string na, float ba) {
    accno = ac;
    accname = na;
    balance = ba;
}
void Account::deposit(float amount) {
    balance += amount;
    cout << balance << " " ;
}
void Account::withdraw(float amount) {
    balance -= amount;
    cout << balance << endl;
    count += balance;
}
float Account::getBalance() {
    return balance = balance * (1 + interestRate);
}
void Account::show() {
    cout << accno << " " << accname << " ";
}

int main()
{
    float rate;
    cin >> rate;
    Account::setInterestRate(rate);
    int t;
    cin >> t;
    while (t--) {
        string no, name;
        float balance,add,minus;
        cin >> no >> name >> balance >> add >> minus;
        Account a(no, name, balance);
        a.show();
        a.deposit(add);
        cout << a.getBalance() << " ";
        a.withdraw(minus);
    }
    cout << Account::getCount() << endl;
	return 0;
}