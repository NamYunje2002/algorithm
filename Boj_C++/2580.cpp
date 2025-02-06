#include <bits/stdc++.h>
using namespace std;

int board[9][9];

void CheckRow(int x, vector<int>& vis) {
	for (int i = 0; i < 9; i++) vis[board[x][i]] = 1;
}

void CheckCol(int y, vector<int>& vis) {
	for (int i = 0; i < 9; i++) vis[board[i][y]] = 1;
}

void CheckSquare(int x, int y, vector<int>& vis) {
	int a = x / 3 * 3;
	int b = y / 3 * 3;
	for (int i = a; i < a + 3; i++) for (int j = b; j < b + 3; j++) vis[board[i][j]] = 1;
}

void Solve(int x, int y, int cnt) {
	if (cnt == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << board[i][j] << " \n"[j == 8];
			}
		}
		exit(0);
	}
	if (board[x][y]) Solve(x + ((y + 1) % 9 == 0), (y + 1) % 9, cnt + 1);
	else {
		vector<int> vis(10, 0);
		CheckRow(x, vis);
		CheckCol(y, vis);
		CheckSquare(x, y, vis);
		for (int i = 1; i <= 9; i++) {
			if (vis[i]) continue;
			board[x][y] = i;
			Solve(x + ((y + 1) % 9 == 0), (y + 1) % 9, cnt + 1);
			board[x][y] = 0;
		}
	}
}

int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
		}
	}
	Solve(0, 0, 0);
}