#include<bits/stdc++.h>

using namespace std;

bool is_bal(string s) {
	int i, n = s.size();
	stack<char> St;
	for (i = 0; i < n; i++) {
		if (s[i] == '{') {
			St.push(s[i]);
		}
		else if (s[i] == '}') {
			if (St.empty())  return false;
			char on_top = St.top();
			if (on_top == '{') {
				St.pop();
			}
			else {
				return false;
			}
		}
		else if (s[i] == '(') {
			St.push(s[i]);

		}
		else if (s[i] == ')') {
			if (St.empty())  return false;
			char on_top = St.top();
			if (on_top == '(') {
				St.pop();
			}
			else {
				return false;
			}
		}
		else if (s[i] == '[') {
			St.push(s[i]);

		}
		else if (s[i] == ']') {
			if (St.empty())  return false;
			char on_top = St.top();
			if (on_top == '[') {
				St.pop();
			}
			else {
				return false;
			}
		}
	}
	if (St.empty()) {
		return true;
	}
	else {
		return false;
	}
}

int main()
{
	string s;
	cin >> s;
	if (is_bal(s)) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
}
