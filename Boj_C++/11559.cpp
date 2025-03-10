#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int ans;
int idx[72], dx[4] = { 0, 1, 0, -1 }, dy[4] = { 1, 0, -1, 0 };
int vis[12][6];
string board[12];

int find() {
	int ret = 0;
	int curNum = 0;
	queue<pair<int, int> > q;
	for (int i = 0; i < 72; i++) idx[i] = 0;
	for (int i = 0; i < 12; i++) for (int j = 0; j < 6; j++) vis[i][j] = -1;
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			if (board[i][j] == '.' || vis[i][j] != -1) continue;
			int cnt = 0;
			vis[i][j] = curNum;
			q.push({ i, j });
			while (!q.empty()) {
				pair<int, int> cur = q.front(); q.pop();
				cnt++;
				for (int k = 0; k < 4; k++) {
					int nx = cur.X + dx[k];
					int ny = cur.Y + dy[k];
					if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;
					if (board[nx][ny] != board[i][j] || vis[nx][ny] != -1) continue;
					vis[nx][ny] = curNum;
					q.push({ nx, ny });
				}
			}
			if (cnt >= 4) ret = idx[curNum] = 1;
			curNum++;
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < 12; i++) cin >> board[i];

	while (find()) {
		ans++;
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (idx[vis[i][j]]) board[i][j] = '.';
			}
		}
		
		for (int i = 10; i >= 0; i--) {
			for (int j = 0; j < 6; j++) {
				if (board[i][j] != '.') {
					int x = i + 1;
					while (x <= 11 && board[x][j] == '.') {
						board[x][j] = board[x - 1][j];
						board[x - 1][j] = '.';
						x++;
					}
				}
			}
		}
	}
	cout << ans;
}