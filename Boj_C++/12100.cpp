// https://www.acmicpc.net/problem/12100

#include <bits/stdc++.h>
using namespace std;

int n, ans; 

vector<vector<int> > merge(vector<vector<int> > board, int seq) {
	vector<vector<int> > vis(n, vector<int>(n, 0));
	if (seq == 0) {
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < n; j++) {
				if (board[j][i] == 0) continue;
				int x = j;
				while (1) {
					x--;
					if (board[x][i] != 0) {
						if (board[x][i] == board[j][i] && vis[x][i] == 0) {
							board[x][i] *= 2;
							vis[x][i] = 1;
							board[j][i] = 0;
						}
						else if(x + 1 != j) {
							board[x + 1][i] = board[j][i];
							board[j][i] = 0;
						}
						break;
					}
					if (x == 0) {
						board[x][i] = board[j][i];
						board[j][i] = 0;
						break;
					}
				}
			}
		}
	}
	else if (seq == 1) {
		for (int i = 0; i < n; i++) {
			for (int j = n - 2; j >= 0; j--) {
				if (board[j][i] == 0) continue;
				int x = j;
				while (1) {
					x++;
					if (board[x][i] != 0) {
						if (board[x][i] == board[j][i] && vis[x][i] == 0) {
							board[x][i] *= 2;
							vis[x][i] = 1;
							board[j][i] = 0;
						}
						else if(x - 1 != j) {
							board[x - 1][i] = board[j][i];
							board[j][i] = 0;
						}
						break;
					}
					else if (x == n - 1) {
						board[x][i] = board[j][i];
						board[j][i] = 0;
						break;
					}
				}
			}
		}
	}
	else if (seq == 2) {
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < n; j++) {
				if (board[i][j] == 0) continue;
				int y = j;
				while (1) {
					y--;
					if (board[i][y] != 0) {
						if (board[i][y] == board[i][j] && vis[i][y] == 0) {
							board[i][y] *= 2;
							vis[i][y] = 1;
							board[i][j] = 0;
						}
						else if(y + 1 != j) {
							board[i][y + 1] = board[i][j];
							board[i][j] = 0;
						}
						break;
					}
					if (y == 0) {
						board[i][y] = board[i][j];
						board[i][j] = 0;
						break;
					}
				}
			}
		}
	}
	else if (seq == 3) {
		for (int i = 0; i < n; i++) {
			for (int j = n - 2; j >= 0; j--) {
				if (board[i][j] == 0) continue;
				int y = j;
				while (1) {
					y++;
					if (board[i][y] != 0) {
						if (board[i][y] == board[i][j] && vis[i][y] == 0) {
							board[i][y] *= 2;
							vis[i][y] = 1;
							board[i][j] = 0;
						}
						else if(y - 1 != j) {
							board[i][y - 1] = board[i][j];
							board[i][j] = 0;
						}
						break;
					}
					if (y == n - 1) {
						board[i][y] = board[i][j];
						board[i][j] = 0;
						break;
					}
				}
			}
		}
	}
	return board;
}

void solve(vector<vector<int> > board, int cnt) {
	if (cnt == 5) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ans = max(ans, board[i][j]);
			}
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		solve(merge(board, i), cnt + 1);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	vector<vector<int> > board(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	solve(board, 0);
	cout << ans;
}
