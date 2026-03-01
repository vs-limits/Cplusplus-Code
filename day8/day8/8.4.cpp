//#include<iostream>
//using namespace std;
//
//class Hotel
//{
//private:
//    static int totalCustNum; // 顾客总人数
//    static float totalEarning; // 旅店总收入
//    static float rent; // 每个顾客的房租
//    string customerName; // 顾客姓名
//    int customerId; // 顾客编号
//public:
//    // totalCustNum++，customerId按照totalCustNum生成
//    Hotel(string customer) :customerName(customer) {};
//    void set_rent(int r){
//        rent = r;
//    };
//    void addEarning() {
//        totalEarning += rent;
//    }
//    void addnum() {
//        totalCustNum += 1;
//    }
//    void setId() {
//        customerId = 20150000 + totalCustNum;
//    }
//    void Display() {
//        cout << customerName << " " << customerId << " " << totalCustNum << " " << totalEarning << endl;
//    }; //相应输出顾客姓名、顾客编号、总人数、总收入
//};
//int Hotel::totalCustNum = 0;
//float Hotel::rent = 0;
//float Hotel::totalEarning = 0;
//
//int main()
//{
//    float rent;
//    cin >> rent;
//    string name;
//    cin >> name;
//    while (name != "0") {
//        Hotel c(name);
//        c.set_rent(rent);
//        c.addnum();
//        c.setId();
//        c.addEarning();
//        c.Display();
//        cin >> name;
//    }
//	return 0;
//}