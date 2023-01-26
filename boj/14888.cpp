// https://www.acmicpc.net/problem/14888

#include <iostream>

using namespace std;

int n, ans[2] = { -0x7f7f7f7f, 0x7f7f7f7f }, arr[12], op[4];

void solve(int k, int cnt) {
	if (cnt == n) {
		if (k > ans[0]) ans[0] = k;
		if (k < ans[1]) ans[1] = k; 
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (op[i] == 0) continue;
		op[i]--;
		if (i == 0) solve(k + arr[cnt], cnt + 1);
		else if (i == 1) solve(k - arr[cnt], cnt + 1);
		else if (i == 2) solve(k * arr[cnt], cnt + 1);
		else solve(k / arr[cnt], cnt + 1);
		op[i]++;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < 4; i++) cin >> op[i];
	solve(arr[0], 1);
	cout << ans[0] << "\n" << ans[1];
}
