#include<bits/stdc++.h>

using namespace std;

class Stack {
public:
	queue<int> Q1, Qr;
	bool empty_stack() {
		return Q1.empty();
	}
	void push(int x) {
		Q1.push(x);
	}
	void pop() {
		stack<int> St;
		while (!Q1.empty()) {
			St.push(Q1.front());
			Q1.pop();
		}
		while (!St.empty()) {
			Qr.push(St.top());
			St.pop();
		}
		Qr.pop();
		while (!Qr.empty()) {
			St.push(Qr.front());
			Qr.pop();
		}
		while (!St.empty()) {
			Q1.push(St.top());
			St.pop();
		}
	}
	int top() {
		if (empty_stack()) return -1;
		else return Q1.front();
	}
};

int main()
{
	Stack St;
	St.push(5);
	St.push(6);
	St.pop();
	cout << St.top();
}
