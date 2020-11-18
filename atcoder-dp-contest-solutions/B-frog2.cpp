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
int main()
{
    int no_of_stones, no_of_steps;
    cin >> no_of_stones >> no_of_steps;

    vector <int> height(no_of_stones + 1, 0);
    for(int i = 1; i <= no_of_stones; i++)
        cin >> height[i];

    const int oo = 1e9;
    vector <int> minimum_cost(no_of_stones + 1, oo);
    minimum_cost[1] = 0;

    for(int i = 2; i <= no_of_stones; i++)
    {
        for(int j = i - 1; j >= max(1, i - no_of_steps); j--)
        {
            minimum_cost[i] = min(minimum_cost[i], minimum_cost[j] + abs(height[i] - height[j]));
        }
    }

    cout << minimum_cost[no_of_stones];
    return 0;
}

