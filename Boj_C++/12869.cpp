#include <bits/stdc++.h>
using namespace std;

int n;
int scv[3];
int dp[61][61][61];

int solve(int a, int b, int c) {
	if (a == 0 && b == 0 && c == 0) dp[a][b][c] = 0;
	if (dp[a][b][c] != -1) return dp[a][b][c];

	dp[a][b][c] = solve(max(0, a - 9), max(0, b - 3), max(0, c - 1)) + 1;
	dp[a][b][c] = min(dp[a][b][c], solve(max(0, a - 9), max(0, b - 1), max(0, c - 3)) + 1);

	dp[a][b][c] = min(dp[a][b][c], solve(max(0, a - 3), max(0, b - 9), max(0, c - 1)) + 1);
	dp[a][b][c] = min(dp[a][b][c], solve(max(0, a - 3), max(0, b - 1), max(0, c - 9)) + 1);

	dp[a][b][c] = min(dp[a][b][c], solve(max(0, a - 1), max(0, b - 9), max(0, c - 3)) + 1);
	dp[a][b][c] = min(dp[a][b][c], solve(max(0, a - 1), max(0, b - 3), max(0, c - 9)) + 1);

	return dp[a][b][c];
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); 
	for (int i = 0; i < 61; i++) for (int j = 0; j < 61; j++) for (int k = 0; k < 61; k++) dp[i][j][k] = -1;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> scv[i];
	solve(scv[0], scv[1], scv[2]);
	cout << dp[scv[0]][scv[1]][scv[2]];
}