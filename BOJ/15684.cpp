#include <bits/stdc++.h>
using namespace std;

int n, m, h, ans = -1;
int arr[32][12];

bool isRight() {
	for (int i = 1; i <= n; i++) {
		int floor = 1, cur = i;
		while (floor <= h) {
			if (arr[floor][cur]) cur = arr[floor][cur];
			floor++;
		}
		if (cur != i) return false;
	}
	return true;
}

void solve(int x, int y, int cnt) {
	if (isRight()) {
		ans == -1 ? ans = cnt : ans = min(ans, cnt);
		return;
	}
	if (cnt == 3) return;
	for (int i = x; i <= h; i++) {
		for (int j = y; j < n; j++) {
			if (arr[i][j] == 0 && arr[i][j + 1] == 0) {
				arr[i][j] = j + 1;
				arr[i][j + 1] = j;
				solve(i, j - 1, cnt + 1);
				arr[i][j] = 0;
				arr[i][j + 1] = 0;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> h;
	while (m--) {
		int a, b; cin >> a >> b;
		arr[a][b] = b + 1;
		arr[a][b + 1] = b;
	}
	solve(1, 1, 0);
	cout << ans;
}
