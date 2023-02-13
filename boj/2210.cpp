// https://www.acmicpc.net/problem/2210

#include <iostream>

using namespace std;

int ans, board[5][5], vis[1000001], dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };

void dfs(int x, int y, int num, int depth) {
	if (depth == 6) {
		if (!vis[num]) {
			vis[num] = 1;
			ans++;
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
        int ny = y + dy[i];
		if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
		dfs(nx, ny, num * 10 + board[nx][ny], depth + 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < 5; i++) 
		for (int j = 0; j < 5; j++) 
			cin >> board[i][j];
		
	for (int i = 0; i < 5; i++) 
		for (int j = 0; j < 5; j++) 
			dfs(i, j, board[i][j], 1);
		
	cout << ans;
}
