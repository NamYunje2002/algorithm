#include <bits/stdc++.h>
using namespace std;

const int MAX = 200001;

int n; 
int adj[22][22], dp[22][1 << 22];

int solve(int cur, int vis) {
	if ((1 << n) - 1 == vis) return 0;
	if (dp[cur][vis] != MAX) return dp[cur][vis];
	for (int i = 0; i < n; i++) {
		if (vis & (1 << i)) continue;
		dp[cur][vis] = min(dp[cur][vis], solve(cur + 1, (vis | (1 << i))) + adj[cur][i]);
	}
	return dp[cur][vis];
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> adj[i][j];
	for (int i = 0; i < 22; i++) for (int j = 0; j < (1 << 22); j++) dp[i][j] = MAX;
	cout << solve(0, 0);
}