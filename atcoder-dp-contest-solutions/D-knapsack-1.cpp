#include <bits/stdc++.h>
using namespace std;
long long int dp[105][100005];
long long int rec(vector<int>& W, vector<int>& V, int n, int w){
	if(n == 0 or w == 0){
		return 0;
	}
	if (dp[n][w] != -1) return dp[n][w];
	else if(w >= W[n-1] ){
		return dp[n][w] = max(V[n-1]+rec(W, V, n-1, w-W[n-1]), rec(W, V, n-1, w));
	}
	else{
			return dp[n][w] = rec(W, V, n-1, w);
	}
}
int main() {
	int n, w;
	cin >> n >> w;
	memset(dp, -1, sizeof(dp));
	vector<int> W(n), V(n);
	for(int i = 0; i < n; i++){
		cin >> W[i];
		cin >> V[i];
	}
	cout << rec(W, V, n, w);
	return 0;
}

