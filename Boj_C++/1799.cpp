// https://www.acmicpc.net/problem/1799

#include <iostream>

using namespace std;

int n, board[11][11], ans[2], dx[2] = { -1, -1 }, dy[2] = { -1, 1 };

bool check(int x, int y) {
	// 놓을 수 없는 경우
	if (board[x][y] == 0) return 0;

	// 왼쪽 대각선과 오른쪽 대각선에 비숍이 놓여있는지 확인
	for (int i = 0; i < 2; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		while (nx >= 1 && ny >= 1 && ny <= n) {
			if (board[nx][ny] == -1) return 0;
			nx += dx[i];
			ny += dy[i];
		}
	}
	return 1;
}

void solve(int x, int y, int cnt) {
	ans[0] = max(cnt, ans[0]);

	// 한 줄을 탐색했을 경우
	if (y > n) {
		x++;
		y = y % 2 ? 2 : 1;
	}

	// 전체를 탐색했을 경우
	if (x > n) return;

	// 놓을 수 있으면 개수 올림
	if (check(x, y)) {
		board[x][y] = -1;
		solve(x, y + 2, cnt + 1);
		board[x][y] = 1;
	}

	// 놓을 수 없으면 개수 그대로
	solve(x, y + 2, cnt);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
		}
	}
	// 홀수 칸 확인
	solve(1, 1, 0);
	ans[1] = ans[0]; 
	ans[0] = 0;

	// 짝수 칸 확인
	solve(1, 2, 0);
	cout << ans[0] + ans[1];
}
