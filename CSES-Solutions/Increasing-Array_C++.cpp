#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define llu unsigned long long
#define endl "\n"

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i) cin >> arr[i];
    vector<int> diff;
    int prev = arr[0];
    for(int i = 1; i < n; ++i) {
        if(prev > arr[i])
            diff.pb(prev-arr[i]);
        else
            prev = arr[i];
    }
    llu sum = 0;
    for(int i: diff)
        sum += i;
    cout << sum << endl;
    return 0;
}
