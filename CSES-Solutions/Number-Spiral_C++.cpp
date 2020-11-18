#include <bits/stdc++.h>
#define forn(i, n) for(int k = i; i<n; ++i)
#define pb push_back
#define ll long long
#define llu unsigned long long
#define nl "\n"

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        llu r, c;
        cin >> r >> c;
        llu max = r>c?r:c;
        llu diag = max*(max-1) + 1;
        if(max&1)
            cout << diag - r + c << nl;
        else
            cout << diag + r - c << nl;
    }
    return 0;
}
