#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

/// Typedef
typedef long long ll;

#define sc1(a) scanf("%lld",&a)
#define sc2(a,b) scanf("%lld %lld",&a,&b)

#define pf1(a) printf("%lld\n",a)
#define pf2(a,b) printf("%lld %lld\n",a,b)

#define vpnt(ans) for(ll i = 0; i < ans.size(); i++) cout << ans[i] << (i + 1 < ans.size() ? ' ' : '\n');
#define apnt(arr, num) for(ll i = 0; i < num; i++) cout << arr[i] << (i + 1 < num ? ' ' : '\n');

#define mx 200005
#define mod 1000000007
#define PI acos(-1.0)
#define eps 1e-7

#define size1 200010

#define no cout << "NO" << endl
#define yes cout << "YES" << endl
#define mem(name, value) memset(name, value, sizeof(name))

#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define case cout << "Case " << t++ << ": ";

typedef vector <ll> vll;
typedef set <ll> sll;
typedef queue <ll> qll;
typedef map <ll, ll> mll;
typedef pair <ll, ll> pll;
typedef vector <pair <ll , ll> > vpll;

inline bool cmp(pll a,pll b){ if(a.ff == b.ff)return a.ss < b.ss; return a.ff > b.ff; }

ll lcm(ll a, ll b)
{
    return (a*b)/__gcd(a, b);
}

int main() {


    ll n, m, num, tc, t = 1;

    sc1(num);
    vll vc;

    for (ll i = 1; i * i <= num; ++i) {
        if(num % i == 0) {
            if(i != num/i) {
                vc.pb(i);
                vc.pb(num / i);
            }
            else vc.pb(i);
        }
    }

    if(num == 1)
        return cout << "1 1" << endl,0;


    ll ln = vc.size(), a = 1;

    for (ll i = ln - 1; i >= 0; i--) {
        for (ll j = 0; j < ln; j++) {
            if(lcm(vc[i], vc[j]) == num && i != j && __gcd(vc[i], vc[j]) == 1) {
                 cout << vc[i] << " " << vc[j] << endl;
                 a = 0;
                break;
            }
        }
        if(a == 0) break;
    }

    if(a)
        printf("%lld %lld\n", a, num);
}
