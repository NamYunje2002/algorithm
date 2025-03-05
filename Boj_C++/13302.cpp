#include <bits/stdc++.h>
using namespace std;

int n, m; 
int arr[102];
int dp[102][40];

int solve(int d, int c) {
	if (d > n) return 0;
	if (dp[d][c] != -1) return dp[d][c];
	dp[d][c] = 1e9;
	dp[d][c] = min(dp[d][c], solve(d + 1, c) + 10000);
	dp[d][c] = min(dp[d][c], solve(d + 3, c + 1) + 25000);
	dp[d][c] = min(dp[d][c], solve(d + 5, c + 2) + 37000);
	if (arr[d]) dp[d][c] = min(dp[d][c], solve(d + 1, c));
	if (c >= 3) dp[d][c] = min(dp[d][c], solve(d + 1, c - 3));
	return dp[d][c];
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	while (m--) {
		int x; cin >> x;
		arr[x] = 1;
	}
	for (int i = 0; i < 102; i++) for (int j = 0; j < 40; j++) dp[i][j] = -1;
	solve(0, 0);
	cout << dp[1][0];
}