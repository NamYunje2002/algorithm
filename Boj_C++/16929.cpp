#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m;
int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };
int vis[55][55];
string ans = "No";
string board[55];

void solve(pair<int, int> cur, pair<int, int> st) {
	for (int i = 0; i < 4; i++) {
		int nx = cur.X + dx[i];
		int ny = cur.Y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if (vis[nx][ny] == 1 && vis[cur.X][cur.Y] >= 4) {
			ans = "Yes";
			return;
		}
		if (board[st.X][st.Y] != board[nx][ny] || vis[nx][ny]) continue;
		vis[nx][ny] = vis[cur.X][cur.Y] + 1;
		solve({ nx, ny }, st);
		vis[nx][ny] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> board[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			vis[i][j] = 1;
			solve({ i, j }, { i, j });
			vis[i][j] = 0;
			if (ans == "Yes") break;
		}
		if (ans == "Yes") break;
	}
	cout << ans;
}