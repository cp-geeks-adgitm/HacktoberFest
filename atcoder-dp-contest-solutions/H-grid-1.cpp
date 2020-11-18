#include <bits/stdc++.h>
using namespace std;
int dp[1002][1002];
const int mod = 1e9+7;
int rec(vector<string>&grid, int i, int j, int h, int w){
	int ans = 0;
	if (i == h-1 and j == w-1){
		return 1;
	}
	else if (i == h or j == w){
		return 0;
	}
	else if (grid[i][j] == '.'){
		if(dp[i][j] != -1){
			return dp[i][j];
		}
		ans += (rec(grid, i+1, j, h, w)+rec(grid, i, j+1, h, w))%mod;
		// cout << "y";
	}
	return dp[i][j] = ans;
}

int main() {
	int h, w;
	cin >> h >> w;
	vector<string>grid;
	memset(dp, -1, sizeof(dp));
	for(int i = 0; i < h; i++){
		string s;
		cin >> s;
		grid.push_back(s);
	}
	cout << rec(grid, 0, 0, h, w) << "\n";
	return 0;
}

