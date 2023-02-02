// https://www.acmicpc.net/problem/1987

#include <iostream>
#include <queue>

using namespace std;

int r, c, ans, vis[27], dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };
string board[22];

void dfs(int x, int y, int cnt) {
	ans = max(cnt, ans);
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
		if (!vis[board[nx][ny] - 65]) {
			vis[board[nx][ny] - 65] = 1;
			dfs(nx, ny, cnt + 1);
			vis[board[nx][ny] - 65] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> board[i];
	}
	vis[board[0][0] - 65] = 1;
	dfs(0, 0, 1);
	cout << ans;
}
