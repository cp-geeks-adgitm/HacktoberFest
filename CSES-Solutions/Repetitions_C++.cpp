#include <bits/stdc++.h>
#define ll long long
#define llu unsigned long long

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    char prev = 'A';
    int count = 0;
    int ans = 0;
    for(char d: s) {
       if(prev == d) {
           ++count;
           ans = max(ans, count);
       }
       else {
           count = 1;
           prev = d;
       }
    }
    cout << ans << "\n";
    return 0;
}
