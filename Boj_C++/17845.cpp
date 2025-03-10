#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, k; cin >> n >> k;
	vector<int> iVec(k + 1), tVec(k + 1);
	vector<vector<int> > dp(k + 1, vector<int>(n + 1));
	for (int i = 0; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			dp[i][j] = 0;
		}
	}
	for (int i = 1; i <= k; i++) {
		cin >> iVec[i] >> tVec[i];
	}

	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			if (j >= tVec[i]) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - tVec[i]] + iVec[i]);
			else dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[k][n];
}