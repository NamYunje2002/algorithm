// https://www.acmicpc.net/problem/3190

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, k, l;
int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };
int dir[10001];
int board[101][101];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	while (k--) {
		int x, y; cin >> x >> y;
		board[x][y] = 1;
	}
	cin >> l;
	while (l--) {
		int x; char c;
		cin >> x >> c;
		dir[x] = c == 'D' ? 1 : -1;
	}
	int ans = 0, cur = 1;
	deque<pair<int, int> > dq;
	dq.push_back({ 1, 1 });
	board[1][1] = 2;
	while (1) {
		int nx = dq.front().X + dx[cur];
		int ny = dq.front().Y + dy[cur];
		if (board[nx][ny] == 2) break;
		if (nx < 1 || nx > n || ny < 1 || ny > n) break;
		board[dq.back().X][dq.back().Y] = 0;
		if (board[nx][ny] == 0) {
			dq.pop_back();
		}
		dq.push_front({ nx,ny });
		board[nx][ny] = 2;
		ans++;
		cur += dir[ans];
		if (cur == 4) cur = 0;
		if (cur == -1) cur = 3;
	}
	cout << ans + 1;
}
