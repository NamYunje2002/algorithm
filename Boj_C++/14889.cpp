// https://www.acmicpc.net/problem/14889

#include <iostream>

using namespace std;

int n, ans = 0x7f7f7f7f, arr[21][21], vis[21];

void solve(int k, int cnt) {
	if (cnt == n / 2) {
		int s = 0, l = 0;
		for (int i = 1; i < n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (vis[i] == 1 && vis[j] == 1) s += arr[i][j] + arr[j][i];
				else if (vis[i] == 0 && vis[j] == 0) l += arr[i][j] + arr[j][i];
			}
		}
		ans = min(ans, abs(s - l));
		return;
	}
	for (k; k <= n; k++) {
		if (vis[k]) continue;
		vis[k] = 1;
		solve(k + 1, cnt + 1);
		vis[k] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];
	solve(1, 0);
	cout << ans;
}
