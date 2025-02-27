#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int prefixSum[1002][1002][3];
string board[1002];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> board[i];
		for (int j = 1; j <= m; j++) {
			for (int k = 0; k < 3; k++) prefixSum[i][j][k] += prefixSum[i][j - 1][k];
			if (board[i][j - 1] == 'J') prefixSum[i][j][0]++;
			else if (board[i][j - 1] == 'O') prefixSum[i][j][1]++;
			else if (board[i][j - 1] == 'I') prefixSum[i][j][2]++;
		}
	}
	while (k--) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		int ans[3] = { 0, 0, 0 };
		for (int i = a; i <= c; i++) for (int j = 0; j < 3; j++) ans[j] += (prefixSum[i][d][j] - prefixSum[i][b - 1][j]);
		for (int i = 0; i < 3; i++) cout << ans[i] << " \n"[i == 2];
	}
}