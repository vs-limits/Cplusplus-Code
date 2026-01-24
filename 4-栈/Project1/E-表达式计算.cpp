#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<cstdlib>
#include<cstring>
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

float Operate(float a, unsigned char theta, float b) {
    if (theta == '+') return a + b;
    if (theta == '-') return a - b;
    if (theta == '*') return a * b;
    if (theta == '/') {
        if (b == 0) {
            cerr << "Error: Division by zero!" << endl;
            exit(1);
        }
        return a / b;
    }
    return 0; // 默认返回值
}

char OPSET[OPSETSIZE] = { '+', '-', '*', '/', '(', ')', '#' };

// 判断字符是否是运算符
Status In(char Test, char* TestOp) {
    for (int i = 0; i < OPSETSIZE; i++) {
        if (Test == TestOp[i])
            return 1; // 是运算符返回1
    }
    return 0; // 不是运算符返回0
}

// 比较运算符优先级
char precede(char Aop, char Bop) {
    int i = -1, j = -1;
    // 查找Aop在OPSET中的位置
    for (int k = 0; k < OPSETSIZE; k++) {
        if (OPSET[k] == Aop) {
            i = k;
            break;
        }
    }
    // 查找Bop在OPSET中的位置
    for (int k = 0; k < OPSETSIZE; k++) {
        if (OPSET[k] == Bop) {
            j = k;
            break;
        }
    }
    // 返回优先级关系
    return Prior[i][j];
}

float EvaluateExpression(string MyExp)
{
    stack<char> OPTR;
    stack<double> OPND;
    char TempData[20];
    double Data, a, b, r;
    char theta, Dr[2];
    char c;
    int i = 0;

    OPTR.push('#');
    c = MyExp[0];

    strcpy(TempData, "\0");
    while (c != '#' || OPTR.top() != '#')
    {
        if (!In(c, OPSET))
        {
            Dr[0] = c;
            Dr[1] = '\0';
            strcat(TempData, Dr);
            c = MyExp[++i]; // 读下一个字符

            // 检查下一个字符是否是运算符或结束符
            if (c == '\0' || In(c, OPSET) || c == '#')
            {
                Data = atof(TempData);
                OPND.push(Data);
                strcpy(TempData, "\0");
            }
        }
        else
        {
            switch (precede(OPTR.top(), c))
            {
            case '<':   // 栈顶元素优先权低
                OPTR.push(c);
                c = MyExp[++i];
                break;
            case '=':   // 脱括号并接收下一字符
                OPTR.pop();  // 弹出左括号
                c = MyExp[++i];  // 读取下一个字符
                break;
            case '>':   // 退栈并将运算结果入栈
                theta = OPTR.top();
                OPTR.pop();
                b = OPND.top();
                OPND.pop();
                a = OPND.top();
                OPND.pop();
                r = Operate(a, theta, b);
                OPND.push(r);
                break;
            default:    // 未知优先级关系
                cerr << "Error: Unknown precedence relation!" << endl;
                exit(1);
            }
        }
    }
    return OPND.top();
}

int main()
{
    string Exp;
    int t;
    double result;
    cin >> t;
    while (t--)
    {
        cin >> Exp;
        Exp += '#'; // 添加结束符
        result = EvaluateExpression(Exp);
        cout << fixed << setprecision(4) << result << endl;
    }
    return 0;
}