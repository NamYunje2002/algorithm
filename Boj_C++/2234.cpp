#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int area[3030], ans[3], dx[4] = { 0, -1, 0, 1 }, dy[4] = { -1, 0, 1, 0 };
int board[55][55], vis[55][55];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int m, n; cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vis[i][j]) continue;
			int cnt = 0;
			queue < pair<int, int> > q;
			vis[i][j] = ++ans[0];
			q.push({ i, j });
			while (!q.empty()) {
				pair<int, int> cur = q.front(); q.pop();
				cnt++;
				for (int k = 0; k < 4; k++) {
					if ((board[cur.X][cur.Y] >> k) & 1) continue;
					int nx = cur.X + dx[k];
					int ny = cur.Y + dy[k];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (vis[nx][ny]) continue;
					vis[nx][ny] = ans[0];
					q.push({ nx,ny });
				}
			}
			area[ans[0]] = cnt;
			ans[1] = max(ans[1], cnt);
			ans[2] = max(ans[2], cnt);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 4; k++) {
				if (!((board[i][j] >> k) & 1)) continue;
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (vis[i][j] != vis[nx][ny]) ans[2] = max(ans[2], area[vis[i][j]] + area[vis[nx][ny]]);
			}
		}
	}
	for (int i = 0; i < 3; i++) cout << ans[i] << '\n';
}