#include <bits/stdc++.h> 
#define pb push_back
#define mp make_pair 
#define fr first
#define sc second
#define MOD 1000000007
#define len(x) x.size()
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define all(v) v.begin(), v.end()
#define alla(a,n) a, a + n
  
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<vll> vvll;
typedef vector<string> vs;
const int MAX = 1e5+5;
int h[MAX];
int dp[MAX];

ll frog(int n){

    for( int i = 2; i < n; i++)
        dp[i] = min(dp[i-2]+abs(h[i-2]-h[i]), dp[i-1]+abs(h[i-1]-h[i])  );
    return dp[n-1];
    
}
int main() {

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin) ;
    // freopen("output.txt", "w", stdout) ;
    // #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    dp[0] =  0;
    dp[1] =  abs(h[1]-h[0]);
    ll a = frog(n);
    cout<<a<<"\n"; 


    return 0 ;

}

