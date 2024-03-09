// https://www.acmicpc.net/problem/14500

#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
int dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };
int board[501][501], vis[501][501];

void dfs(int x, int y, int sum, int length) {
	if (length == 4) {
		ans = max(ans, sum);
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if (vis[nx][ny]) continue;
		if (length == 2) {
			vis[nx][ny] = 1;
			dfs(x, y, sum + board[nx][ny], length + 1);
			vis[nx][ny] = 0;
		}
		vis[nx][ny] = 1;
		dfs(nx, ny, sum + board[nx][ny], length + 1);
		vis[nx][ny] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			vis[i][j] = 1;
			dfs(i, j, board[i][j], 1);
			vis[i][j] = 0;
		}
	}
	cout << ans;
}
