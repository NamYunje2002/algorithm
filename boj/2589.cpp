// https://www.acmicpc.net/problem/2589

#include <iostream>
#include <queue>
#include <cstring>

#define X first
#define Y second

using namespace std;

int n, m, ans, vis[52][52], dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };
char map[52][52];
queue<pair<int, int>> Q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
		
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 'L') {
				vis[i][j] = 1;
				Q.push({ i,j });
			}
			while (!Q.empty()) {
				pair<int, int> cur = Q.front(); Q.pop();
				for (int i = 0; i < 4; i++) {
					int nx = cur.X + dx[i];
					int ny = cur.Y + dy[i];

					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (vis[nx][ny] || map[nx][ny] == 'W') continue;
                    
					vis[nx][ny] = vis[cur.X][cur.Y] + 1;
					ans = max(vis[nx][ny] - 1, ans);
					Q.push({ nx,ny });
				}
			}
			memset(vis, 0, sizeof(vis));
		}
	}
	cout << ans;
}
