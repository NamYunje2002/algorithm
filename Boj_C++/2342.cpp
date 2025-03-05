#include <bits/stdc++.h>
using namespace std;

int n;
int dp[5][5][100002];
int arr[100002];

int getForce(int cur, int nxt) {
	if (cur == 0) return 2;
	if (abs(cur - nxt) == 2) return 4;
	return 3;
}

int solve(int l, int r, int ct) {
	if (ct > n) return 0;
	if (dp[l][r][ct] != 1e9) return dp[l][r][ct];
	int nxt = arr[ct];
	if (l == nxt || r == nxt) {
		dp[l][r][ct] = min(dp[l][r][ct], solve(l, r, ct + 1) + 1);
	} else {
		dp[l][r][ct] = min(dp[l][r][ct], solve(nxt, r, ct + 1) + getForce(l, nxt));
		dp[l][r][ct] = min(dp[l][r][ct], solve(l, nxt, ct + 1) + getForce(r, nxt));
	}
	return dp[l][r][ct];
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	while (1) {
		int x; cin >> x;
		if (x == 0) break;
		arr[++n] = x;
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 100002; k++) {
				dp[i][j][k] = 1e9;
			}
		}
	}
	solve(0, 0, 1);
	cout << dp[0][0][1];
}