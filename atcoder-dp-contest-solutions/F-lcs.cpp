#include<bits/stdc++.h>
using namespace std;

int main(){
  string s, t;
  cin >> s >> t;
  int sl = s.size();
  int tl = t.size();
  int dp[sl+1][tl+1];
  for(int i = 0; i <= sl; i++){
    for(int j = 0; j <= tl; j++){
      if(i == 0 or j == 0){
        dp[i][j] = 0;
      }
      else if(s[i-1] == t[j-1]){
        dp[i][j] = 1+dp[i-1][j-1];
      }
      else{
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }
  int i = sl, j = tl;
  vector<char> str;
  while(i > 0 && j > 0){
    if(s[i-1] == t[j-1]){
      str.push_back(s[i-1]);
      i--;
      j--;
    }
    else{
    	if(dp[i][j-1] > dp[i-1][j]) j--;
    	else i--;
    }
            
  }
  reverse(str.begin(), str.end());
  for(int i = 0; i < str.size(); i++){
    cout << str[i];
  }
  cout << "\n";
}

