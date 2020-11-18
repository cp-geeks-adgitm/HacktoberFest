#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
int main() {
 
	
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int ans = 1;
	
	vector<int> rg(n, 1);
	for (int i = n - 2; i >= 0; --i) {
		if (a[i + 1] > a[i]) rg[i] = rg[i + 1] + 1;
		ans = max(ans, rg[i]);
	}
	
	vector<int> lf(n, 1);
	for (int i = 1; i < n; ++i) {
		if (a[i - 1] < a[i]) lf[i] = lf[i - 1] + 1;
		ans = max(ans, lf[i]);
	}
	
	for (int i = 0; i < n - 2; ++i) {
		if (a[i] < a[i + 2]) ans = max(ans, lf[i] + rg[i + 2]);
	}
	
	cout << ans << endl;
	
	return 0;
}
