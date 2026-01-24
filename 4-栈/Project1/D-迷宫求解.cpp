#include<iostream>
#include<stack>
using namespace std;
struct point{
	int x;
	int y;
};

stack<point> path;
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };//方向数组

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int** puzzle = new int* [n];
		for (int i = 0; i < n; i++) {
			puzzle[i] = new int[n];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> puzzle[i][j];
			}
		}

		int** vis = new int* [n];
		for (int i = 0; i < n; i++) {
			vis[i] = new int[n];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				vis[i][j] = false;
			}
		}

		path.push({0,0});
		

		while (!path.empty()) {
			bool move = false;
			int x = path.top().x, y = path.top().y;
			vis[x][y] = true;
			if (puzzle[0][0] == 1) {
				path.pop();
				break;
			}
			if (x == n - 1 && y == n - 1) {
				break; //保留路径path
			}
			for (int i = 0; i < 4; i++) {
				int xx = x + dir[i][0];
				int yy = y + dir[i][1];
				if(xx >= 0 && xx < n && yy >= 0 && yy < n && puzzle[xx][yy] == 0 && !vis[xx][yy] && !move) {
					move = true;
					point p;
					p.x = xx;
					p.y = yy;
					path.push(p);
					break;
				}
			}
			if (!move) {
				path.pop();
			}
		}
		//path�Ǳ���·���Ķ�ջ����ջ��ÿ��Ԫ�ض�����x�����y���꣬������xp��yp��ʾ
			//path1��һ����ʱ��ջ����path�����ݵ��������path1��ʹ��·�����������
			if (!path.empty())  //�ҵ�·��
			{   
				stack<point> path1;
				while(!path.empty())
				{
					path1.push(path.top());
					path.pop();
				}
				point cpos;
				int i = 0;  //���������·���Ĵ���
				while (!path1.empty())
				{
					cpos = path1.top();
					if ((++i) % 4 == 0)
						cout << '[' << cpos.x << ',' << cpos.y << ']' << "--" << endl;
					else
						cout << '[' << cpos.x << ',' << cpos.y << ']' << "--";
					path1.pop();
				}
				cout << "END" << endl;
			}
			else
				cout << "no path" << endl; //�Ҳ���·�����no path
	}
}