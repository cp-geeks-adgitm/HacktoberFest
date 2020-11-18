#include <bits/stdc++.h>
#define ll long long
#define llu unsigned long long

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    llu n;
    cin >> n;
    cout << n << " ";
    while(n != 1) {
        if(n & 1)
           n = 3*n + 1;
        else
           n >>= 1;
        cout << " " << n;
    }
    return 0;
}
