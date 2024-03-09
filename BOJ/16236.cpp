#include <iostream>
#include <queue>

#define X first
#define Y second

using namespace std;

int n, ans, eatCnt, fishSize = 2;
int g[22][22], vis[22][22], dist[22][22], dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };

queue<pair<int, int>> Q;

bool isChange(pair<int, int> feed, pair<int, int> target) {
	if (feed.X == -1) {
		return 1;
	}
	else {
		if (dist[feed.X][feed.Y] > dist[target.X][target.Y]) {
			return 1;
		}
		else if (dist[feed.X][feed.Y] == dist[target.X][target.Y]) {
			if (feed.X > target.X) {
				return 1;
			}
			else if (feed.X == target.X) {
				if (feed.Y > target.Y) {
					return 1;
				}
			}
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> g[i][j];
			if (g[i][j] == 9) {
				Q.push({ i,j });
				vis[i][j] = 1;
				g[i][j] = 0;
			}
		}
	}
	while (1) {
		pair<int, int> feed = { -1, -1 };
		while (!Q.empty()) {
			pair<int, int> cur = Q.front(); Q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = cur.X + dx[i];
				int ny = cur.Y + dy[i];

				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				if (vis[nx][ny] || g[nx][ny] > fishSize) continue;

				Q.push({ nx,ny });
				vis[nx][ny] = 1;
				dist[nx][ny] = dist[cur.X][cur.Y] + 1;

				if (g[nx][ny] && g[nx][ny] < fishSize) {
					if (isChange(feed, {nx, ny})) {
						feed.X = nx;
						feed.Y = ny;
					}
				}
			}
		}
		if (feed.X == -1) break;

		eatCnt++;
		if (eatCnt == fishSize) {
			eatCnt = 0;
			fishSize++;
		}
		ans += dist[feed.X][feed.Y];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				vis[i][j] = 0;
				dist[i][j] = 0;
			}
		}
		Q.push({feed.X, feed.Y});
		g[feed.X][feed.Y] = 0;
		vis[feed.X][feed.Y] = 1;
	}
	cout << ans;
}
