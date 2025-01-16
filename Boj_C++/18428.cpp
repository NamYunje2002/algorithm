#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
char board[10][10];
string ans = "NO";
vector<pair<int, int> > teacherLoc;

void solve(int cnt) {
	if (cnt == 3) {
		int flag = 1;
		for (const auto& loc : teacherLoc) {
			for (int i = 0; i < 4; i++) {
				int curX = loc.X;
				int curY = loc.Y;
				while (0 <= curX && curX < n && 0 <= curY && curY < n) {
					if (board[curX][curY] == 'O') break;
					if (board[curX][curY] == 'S') flag = 0;
					curX += dx[i];
					curY += dy[i];
				}
			}
		}
		if (flag) ans = "YES";
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 'X') {
				board[i][j] = 'O';
				solve(cnt + 1);
				board[i][j] = 'X';
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'T') teacherLoc.push_back({ i, j });
		}
	}
	solve(0);
	cout << ans;
}