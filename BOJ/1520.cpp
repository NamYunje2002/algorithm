#include <iostream>
using namespace std;

int n, m, ans;
int map[501][501], dp[501][501];
int dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };

int dfs(int x, int y) {
	if (x == n && y == m) return 1;
	if (dp[x][y] != -1) return dp[x][y];
	dp[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (x <= 0 || x > n || y <= 0 || y > m) continue;
		if (map[nx][ny] >= map[x][y]) continue;
		dp[x][y] += dfs(nx, ny);
	}
	return dp[x][y];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
			dp[i][j] = -1;
		}
	}
	cout << dfs(1, 1);
}