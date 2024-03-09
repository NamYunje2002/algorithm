// https://www.acmicpc.net/problem/14502

#include <iostream>
#include <queue>

#define X first
#define Y second

using namespace std;

int n, m, ans;
int lab[10][10], dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };
queue<pair<int, int>> Q;

void BFS() {
	int safeZone = n * m, g[10][10] = { 0, }, vis[10][10] = { 0, };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			g[i][j] = lab[i][j];
			if (g[i][j] == 2) {
				vis[i][j] = 1;
				Q.push({ i,j });
			}
			else if (g[i][j] == 1)
				safeZone--;
		}
	}
	while (!Q.empty()) {
		safeZone--;
		pair<int, int> cur = Q.front(); Q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (vis[nx][ny] || g[nx][ny] != 0) continue;
			g[nx][ny] = 2;
			vis[nx][ny] = 1;
			Q.push({ nx,ny });
		}
	}
	ans = max(ans, safeZone);
}

void makeWall(int cnt) {
	if (cnt == 3) {
		BFS();
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (lab[i][j] == 0) {
				lab[i][j] = 1;
				makeWall(cnt + 1);
				lab[i][j] = 0;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> lab[i][j];
		}
	}
	makeWall(0);
	cout << ans;
}
