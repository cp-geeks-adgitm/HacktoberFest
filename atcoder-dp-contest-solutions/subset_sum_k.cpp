#include <bits/stdc++.h>

using namespace std;

bool subsetSumK(vector<int> &v, int k)
{
    if(k > accumulate(v.begin(), v.end(), 0))
    {
        return false;
    }
    int sum = k, n = v.size();
    bool dp[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (j == 0)
            {
                dp[i][j] = true;
            }
            else if (i == 0)
            {
                dp[i][j] = false;
            }
            else if (v[i - 1] <= j)
            {
                dp[i][j] = dp[i][j - v[i - 1]] || dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][sum];
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, k;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cin >> k;
    bool present = subsetSumK(v, k);
    if (present)
    {
        cout << "subset with sum " << k << " is present";
    }
    else
    {
        cout << "subset with sum " << k << " is not present";
    }
}