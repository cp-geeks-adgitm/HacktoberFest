#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int>v[n+1], dp[n+1];
	for(int i = 0; i < n; i++){
		int a, b, c;
		cin >> a >> b >> c;
		v[i].push_back(a);
		v[i].push_back(b);
		v[i].push_back(c);
		dp[i].push_back(0);
		dp[i].push_back(0);
		dp[i].push_back(0);
	}
	dp[0][0] = v[0][0];
	dp[0][1] = v[0][1];
	dp[0][2] = v[0][2];
	for(int i = 1; i < n; i++){
			dp[i][0] = v[i][0]+max(dp[i-1][1], dp[i-1][2]);
			dp[i][1] = v[i][1]+max(dp[i-1][0], dp[i-1][2]);
			dp[i][2] = v[i][2]+max(dp[i-1][0], dp[i-1][1]);
			
	}
	cout << *max_element(dp[n-1].begin(), dp[n-1].end()) << "\n";
	return 0;
}

