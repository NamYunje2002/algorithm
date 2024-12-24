// https://www.acmicpc.net/problem/14501

#include <iostream>

using namespace std;

int n, ans, t[17], p[17], dp[17];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> t[i] >> p[i];
	for (int i = n; i >= 1; i--) {
		if (n - i + 1 >= t[i])
			dp[i] = max(dp[i + 1], dp[i + t[i]] + p[i]);
		else 
			dp[i] = dp[i + 1];
		ans = max(ans, dp[i]);
	}
	cout << ans;
}
