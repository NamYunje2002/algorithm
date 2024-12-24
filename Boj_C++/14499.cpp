/*
  2
4 1 3
  5
  6
  
  바닥 면 : 1
  윗 면 : 6
  상 : 2
  하 : 5
  좌 : 4
  우 : 3
*/

#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, k;
int dx[4] = { 0, 0, -1, 1 }, dy[4] = { 1, -1, 0, 0 };
int dice[6];
int board[21][21];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	while (k--) {
		int c; cin >> c;
		if (x + dx[c - 1] < 0 || x + dx[c - 1] >= n || y + dy[c - 1] < 0 || y + dy[c - 1] >= m) continue;

		if (c == 1) {
			int tmp = dice[0];
			dice[0] = dice[2];
			dice[2] = dice[5];
			dice[5] = dice[3];
			dice[3] = tmp;
		}
		if (c == 2) {
			int tmp = dice[0];
			dice[0] = dice[3];
			dice[3] = dice[5];
			dice[5] = dice[2];
			dice[2] = tmp;
		}
		if (c == 3) {
			int tmp = dice[0];
			dice[0] = dice[1];
			dice[1] = dice[5];
			dice[5] = dice[4];
			dice[4] = tmp;
		}
		if (c == 4) {
			int tmp = dice[0];
			dice[0] = dice[4];
			dice[4] = dice[5];
			dice[5] = dice[1];
			dice[1] = tmp;
		}

		x += dx[c - 1];
		y += dy[c - 1];
		if (board[x][y] == 0) board[x][y] = dice[0];
		else {
			dice[0] = board[x][y];
			board[x][y] = 0;
		}
		cout << dice[5] << '\n';
	}
}
