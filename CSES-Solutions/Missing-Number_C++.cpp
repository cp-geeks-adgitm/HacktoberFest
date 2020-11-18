#include <bits/stdc++.h>
#define ll long long
#define llu unsigned long long

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    llu x = 1;
    for(int i = 2; i <= n; ++i) x ^= i;
    for(int i = 0; i < n-1; ++i) {
        llu b;
        cin >> b;
        x ^= b;
    }
    cout << x << "\n";
    return 0;
}
