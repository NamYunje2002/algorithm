#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m, k;
int dx[8] = { 1, 0, -1, 0, -1, 1, 1, -1 };
int dy[8] = { 0, 1, 0, -1, 1, 1, -1, -1 };
int dp[15][15][10];
string s;
string G[15];

int solve(pair<int, int> cur, int len) {
	if (G[cur.X][cur.Y] != s[len]) return 0;
	if (len == (int)s.size() - 1) return ++dp[cur.X][cur.Y][len];
	for (int i = 0; i < 8; i++) {
		int nx = (cur.X + dx[i] + n) % n;
		int ny = (cur.Y + dy[i] + m) % m;
		if (dp[nx][ny][len + 1]) dp[cur.X][cur.Y][len] += dp[nx][ny][len + 1];
		else dp[cur.X][cur.Y][len] += solve({nx, ny}, len + 1);
	}
	return dp[cur.X][cur.Y][len];
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) cin >> G[i];
	while (k--) {
		cin >> s;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				ans += solve({ i,j }, 0);
			}
		}
		cout << ans << "\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				for (int k = 0; k < 10; k++) {
					dp[i][j][k] = 0;
				}
			}
		}
	}
}