/#include<bits/stdc++.h>
using namespace std;
vector<int> dp(100005);
bool vis[100005];
int dfs(vector<vector<int>>& adj, int i){
  if(vis[i]){
    return dp[i];
  }
  int ans = 0;
  vis[i] = 1;
  for(int j = 0; j < adj[i].size(); j++){
    ans = max(ans, 1+dfs(adj, adj[i][j]));
  }
  return dp[i] = ans;
}
int main(){
  int n, m;
  cin >> n >> m;
  memset(vis, 0, sizeof(dp));
  fill(dp.begin(), dp.end(), 0);
  vector<vector<int>> adj(n+1);
  for(int i = 0; i < m; i++){
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    
  }
  //dfs(adj, 1);
  for(int i = 1; i < n+1; i++){
    if(!vis[i]){
      dfs(adj, i);
    }
  }
  cout << *max_element(dp.begin(), dp.end()) << "\n";

}

