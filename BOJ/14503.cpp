// https://www.acmicpc.net/problem/14503

#include <bits/stdc++.h>
using namespace std;

int n, m, r, c, d, ans;
int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };
int board[52][52];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); 
	cin >> n >> m >> r >> c >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	while (1) {
		// 현재 칸이 아직 청소되지 않은 경우
		if (board[r][c] == 0) {
			board[r][c] = 2;
			ans++;
			continue;
		}
		// 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우
		if (board[r - 1][c] == 0 || board[r][c - 1] == 0 || board[r + 1][c] == 0 || board[r][c + 1] == 0) {
			//반시계 방향으로 90도 회전
			d = (d - 1 < 0 ? 3 : d - 1);

			// 바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진
			if (board[r + dx[d]][c + dy[d]] == 0) {
				r += dx[d];
				c += dy[d];
			}
		}
		// 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우
		else {
			// 바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춘다.
			if (board[r - dx[d]][c - dy[d]] == 1) break;

			// 바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진
			r -= dx[d];
			c -= dy[d];
		}
	}
	cout << ans;
}
