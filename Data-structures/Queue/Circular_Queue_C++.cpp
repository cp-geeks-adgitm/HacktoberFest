#include<bits/stdc++.h>
using namespace std;
const int N = 5;


class Queue {
private:
	int a[N], first, last, cnt;
public:
	Queue() {
		first = 0;
		last = -1;
		cnt = 0;
	}
	
	void push(int val) {
		if (isfull()) return ;
		cnt++;
		last++;
		last %= N;
		a[last] = val;
	}
	
	int pop() {
		if (isempty()) return -1;
		cnt--;
		int temp = first;
		first++;
		first %= N;
		return a[temp];
	}
	
	bool isempty() {
		return cnt == 0;
	}
	
	bool isfull() {
		return cnt == N;
	}
	
	
};




int main()
{
	Queue Q;
	if (Q.isempty()) {
		cout << "Hey this is empty";
	}
	
	
	Q.push(1);
	Q.push(2);
	Q.push(3);
	Q.push(4);
	Q.push(5);
	if (Q.isfull()) {
		cout << "Hey this is full";
	}
}
