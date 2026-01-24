#include<iostream>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<stack>
using namespace std;

#define OK 0
#define ERROR -1
#define OVERFLOW -1
#define OPSETSIZE 7
typedef int Status;
char Prior[7][7] = {
   '>', '>', '<', '<', '<', '>', '>',
   '>', '>', '<', '<', '<', '>', '>',
   '>', '>', '>', '>', '<', '>', '>',
   '>', '>', '>', '>', '<', '>', '>',
   '<', '<', '<', '<', '<', '=', ' ',
   '>', '>', '>', '>', ' ', '>', '>',
   '<', '<', '<', '<', '<', ' ', '='
};

char OPSET[OPSETSIZE] = { '+', '-', '*', '/', '(', ')', '#' };

Status In(char Test, char* TestOp) {
   for (int i = 0; i < OPSETSIZE; i++) {
       if (Test == TestOp[i])
           return 1;
   }
   return 0;
}

char precede(char Aop, char Bop) {
   int i, j;
   for (i = 0; i < OPSETSIZE; i++) {
       if (OPSET[i] == Aop) break;
   }
   for (j = 0; j < OPSETSIZE; j++) {
       if (OPSET[j] == Bop) break;
   }
   return Prior[i][j];
}

float Operate(float a, unsigned char theta, float b) {
   switch (theta) {
   case '+': return a + b;
   case '-': return a - b;
   case '*': return a * b;
   case '/':
       if (b == 0) {
           cerr << "Error: Division by zero!" << endl;
           exit(1);
       }
       return a / b;
   default: return 0;
   }
}

float EvaluateExpression(string MyExp) {
   stack<char> OPTR;
   stack<double> OPND;
   string numStr = "";  // ʹ��string�����ַ�����
   double Data, a, b, r;
   char theta;
   char c;
   int i = 0;

   OPTR.push('#');
   c = MyExp[i];

   while (c != '#' || OPTR.top() != '#') {
       if (!In(c, OPSET)) {
           numStr += c;  // ֱ�����ӵ��ַ���
           c = MyExp[++i];
           if (In(c, OPSET) || c == '#') {
               Data = stod(numStr);  // ʹ��stodת���ַ���
               OPND.push(Data);
               numStr = "";  // ����ַ���
           }
       }
       else {
           switch (precede(OPTR.top(), c)) {
           case '<':
               OPTR.push(c);
               c = MyExp[++i];
               break;
           case '=':
               OPTR.pop();
               c = MyExp[++i];
               break;
           case '>':
               theta = OPTR.top();
               OPTR.pop();
               b = OPND.top();
               OPND.pop();
               a = OPND.top();
               OPND.pop();
               r = Operate(a, theta, b);
               OPND.push(r);
               break;
           }
       }
   }
   return OPND.top();
}

int main() {
   string Exp;
   int t;
   double result;
   cin >> t;
   while (t--) {
       cin >> Exp;
       Exp += '#'; // ���ӽ�����
       result = EvaluateExpression(Exp);
       cout << fixed << setprecision(4) << result << endl;
   }
   return 0;
}