#include <bits/stdc++.h>
using namespace std;

int n, m, ans = 64, cctv;
int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };
int board[9][9], dir[9][9], arr[9][9], vis[9][9];

int count() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = board[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1) {
				int nx = i, ny = j;
				while (1) {
					nx += dx[dir[i][j]];
					ny += dy[dir[i][j]];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m || arr[nx][ny] == 6) break;
					if (arr[nx][ny] != 0) continue;
					arr[nx][ny] = -1;
				}
			}
			if (arr[i][j] == 2) {
				for (int k = dir[i][j]; k < dir[i][j] + 3; k += 2) {
					int nx = i, ny = j;
					while (1) {
						nx += dx[k];
						ny += dy[k];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m || arr[nx][ny] == 6) break;
						if (arr[nx][ny] != 0) continue;
						arr[nx][ny] = -1;
					}
				}
			}
			if (arr[i][j] == 3) {
				if (dir[i][j] == 3) {
					int t = dir[i][j];
					for(int k = 0; k < 2; k++) {
						int nx = i, ny = j;
						while (1) {
							nx += dx[t];
							ny += dy[t];
							if (nx < 0 || nx >= n || ny < 0 || ny >= m || arr[nx][ny] == 6) break;
							if (arr[nx][ny] != 0) continue;
							arr[nx][ny] = -1;
						}
						t = 0;
					}
				}
				else {
					for (int k = dir[i][j]; k < dir[i][j] + 2; k++) {
						int nx = i, ny = j;
						while (1) {
							nx += dx[k];
							ny += dy[k];
							if (nx < 0 || nx >= n || ny < 0 || ny >= m || arr[nx][ny] == 6) break;
							if (arr[nx][ny] != 0) continue;
							arr[nx][ny] = -1;
						}
					}
				}
			}
			if (arr[i][j] == 4) {
				if (dir[i][j] == 2) {
					int t = dir[i][j];
					for(int k = 0; k < 3; k++) {
						int nx = i, ny = j;
						while (1) {
							nx += dx[t];
							ny += dy[t];
							if (nx < 0 || nx >= n || ny < 0 || ny >= m || arr[nx][ny] == 6) break;
							if (arr[nx][ny] != 0) continue;
							arr[nx][ny] = -1;
						}
						if (k == 0) t++;
						else t = 0;
					}
				}
				else if (dir[i][j] == 3) {
					int t = dir[i][j];
					for(int k = 0; k < 3; k++) {
						int nx = i, ny = j;
						while (1) {
							nx += dx[t];
							ny += dy[t];
							if (nx < 0 || nx >= n || ny < 0 || ny >= m || arr[nx][ny] == 6) break;
							if (arr[nx][ny] != 0) continue;
							arr[nx][ny] = -1;
						}
						if (k == 0) t = 0;
						else t++;
					}
				}
				else {
					for (int k = dir[i][j]; k < dir[i][j] + 3; k++) {
						int nx = i, ny = j;
						while (1) {
							nx += dx[k];
							ny += dy[k];
							if (nx < 0 || nx >= n || ny < 0 || ny >= m || arr[nx][ny] == 6) break;
							if (arr[nx][ny] != 0) continue;
							arr[nx][ny] = -1;
						}
					}
				}
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) cnt++;
		}
	}
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++) {
	//		if (arr[i][j] == -1) cout << 9 << ' ';
	//		else cout << arr[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}
	//cout << "\n\n";
	return cnt;
}

void solve(int x, int y) {
	ans = min(ans, count());
	for (int i = x; i < n; i++) {
		for (int j = y; j < m; j++) {
			if (board[i][j] == 2 && dir[i][j] == 0) {
				dir[i][j] = 1;
				solve(i, j - 1);
				dir[i][j] = 0;
			}
			if (vis[i][j]) continue;
			if (board[i][j] == 1 || board[i][j] == 3 || board[i][j] == 4) {
				vis[i][j] = 1;
				for (int k = 1; k < 4; k++) {
					dir[i][j] = k;
					solve(i, j - 1);
				}
				dir[i][j] = 0;
				vis[i][j] = 0;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 5) {
				for (int k = 0; k < 4; k++) {
					int nx = i, ny = j;
					while (1) {
						nx += dx[k];
						ny += dy[k];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] == 6) break;
						if (board[nx][ny] != 0) continue;
						board[nx][ny] = -1;
					}
				}
			}
		}
	}
	solve(0, 0);
	cout << ans;
}