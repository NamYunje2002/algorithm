#include <bits/stdc++.h>
using namespace std;

int x, y, maxLen;
int pArr[5005], nArr[5005];
int board[55][55];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	pArr[0] = nArr[0] = 1;
	int p = 8;
	for (int i = 1; i < 5005; i++) {
		pArr[i] = pArr[i - 1] + p;
		p += 8;
	}

	p = 4;
	for (int i = 1; i < 5005; i++) {
		nArr[i] = nArr[i - 1] + p;
		p += 8;
	}

	int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
	for (int i = r1; i <= r2; i++) {
		for (int j = c1; j <= c2; j++) {
			if (i == j) {
				if (i > 0) board[x][y] = pArr[i];
				else if (i < 0) board[x][y] = nArr[abs(i)];
				else board[x][y] = 1;
			} else {
				int mx = abs(i) > abs(j) ? i : j;
				if (mx == i) {
					p = abs(mx - i) + abs(mx - j);
					if (i > 0) board[x][y] = pArr[abs(mx)] - p;
					else board[x][y] = nArr[abs(mx)] - p;
				}
				else {
					p = abs((mx * -1) - i) + abs((mx * -1) - j);
					if (j < 0) board[x][y] = pArr[abs(mx)] - p;
					else board[x][y] = nArr[abs(mx)] - p;
				}
			}
			maxLen = max(maxLen, (int)to_string(board[x][y]).size());
			y++;
		}
		x++;
		y = 0;
	}
	for (int i = 0; i <= r2 - r1; i++) {
		for (int j = 0; j <= c2 - c1; j++) {
			int cur = board[i][j];
			for (int k = (int)to_string(cur).size(); k < (int)maxLen; k++) {
				cout << " ";
			}
			cout << cur << " ";
		}
		cout << "\n";
	}
}