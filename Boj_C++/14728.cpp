#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, t; cin >> n >> t;
	vector<int> kv(n + 1, 0), sv(n + 1, 0);
	vector<vector<int> > dp(n + 1, vector<int>(t + 1, 0));
	for (int i = 1; i <= n; i++) cin >> kv[i] >> sv[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= t; j++) {
			if (j >= kv[i]) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - kv[i]] + sv[i]);
			else dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[n][t];
}