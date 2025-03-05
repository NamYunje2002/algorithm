#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = { 0, 1, 0, -1 }, dy[4] = { 1, 0, -1, 0 };

void solve(vector<string>& board, int moveCnt, int& ans) {
	ans = max(ans, moveCnt);
	for (int i = 0; i < 5; i++) {
		for (int j = 0 ;j < 9; j++) {
			if (board[i][j] == 'o') {
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx < 0 || nx >= 5 || ny < 0 || ny >= 9) continue;
					if (board[nx][ny] == 'o') {
						int tx = nx + dx[k];
						int ty = ny + dy[k];
						if (tx < 0 || tx >= 5 || ty < 0 || ty >= 9) continue;
						if (board[tx][ty] == '#' || board[tx][ty] == 'o') continue;
						board[i][j] = '.';
						board[nx][ny] = '.';
						board[tx][ty] = 'o';
						solve(board, moveCnt + 1, ans);
						board[i][j] = 'o';
						board[nx][ny] = 'o';
						board[tx][ty] = '.';
					}
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int totalCnt = 0;
		vector<string> board(5);
		for (int i = 0; i < 5; i++) {
			cin >> board[i];
			for (int j = 0; j < 9; j++) {
				if (board[i][j] == 'o') totalCnt++;
			}
		}
		int ans = -1;
		solve(board, 0, ans);
		cout << totalCnt - ans << " " << ans << "\n";
	}
}