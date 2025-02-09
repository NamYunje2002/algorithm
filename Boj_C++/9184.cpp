#include <bits/stdc++.h>
using namespace std;

int dp[105][105][105];

int w(int a, int b, int c) {
	if (dp[a][b][c]) return dp[a][b][c];
	if (a <= 50 || b <= 50 || c <= 50) return dp[a][b][c] = 1;
	if (a > 70 || b > 70 || c > 70) return dp[a][b][c] = w(70, 70, 70);
	if (a < b && b < c) {
		dp[a][b][c - 1] = w(a, b, c - 1);
		dp[a][b - 1][c - 1] = w(a, b - 1, c - 1);
		dp[a][b - 1][c] = w(a, b - 1, c);
		dp[a][b][c] = dp[a][b][c - 1] + dp[a][b - 1][c - 1] - dp[a][b - 1][c];
		return dp[a][b][c];
	}
	else {
		dp[a - 1][b][c] = w(a - 1, b, c);
		dp[a - 1][b - 1][c] = w(a - 1, b - 1, c);
		dp[a - 1][b][c - 1] = w(a - 1, b, c - 1);
		dp[a - 1][b - 1][c - 1] = w(a - 1, b - 1, c - 1);
		dp[a][b][c] = dp[a - 1][b][c] + dp[a - 1][b - 1][c] + dp[a - 1][b][c - 1] - dp[a - 1][b - 1][c - 1];
		return dp[a][b][c];
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 105; i++) for (int j = 0; j < 105; j++) for (int k = 0; k < 105; k++) w(i, j, k);
	while (1) {
		int a, b, c; cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) break;
		cout << "w(" << a << ", " << b << ", " << c << ") = " << dp[a + 50][b + 50][c + 50] << "\n";
	}
}