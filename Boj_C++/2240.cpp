#include <bits/stdc++.h>
using namespace std;

int t, w;
int plum[1002];
int dp[1002][32][1002];

int solve(int cl, int mc, int ct) {
	if (ct > t) return 0;
	if (dp[cl][mc][ct] != -1) return dp[cl][mc][ct];
	dp[cl][mc][ct] = 0;
	dp[cl][mc][ct] += solve(cl, mc, ct + 1) + (plum[ct] == cl);
	if (mc < w) dp[cl][mc][ct] = max(dp[cl][mc][ct], solve(cl % 2 + 1, mc + 1, ct + 1) + (plum[ct] == cl % 2 + 1));
	return dp[cl][mc][ct];
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> t >> w;
	for (int i = 0; i < 1002; i++) {
		for (int j = 0; j < 32; j++) {
			for (int k = 0; k < 1002; k++) {
				dp[i][j][k] = -1;
			}
		}
	}
	for (int i = 1; i <= t; i++) cin >> plum[i];
	solve(1, 0, 1);
	cout << dp[1][0][1];
}