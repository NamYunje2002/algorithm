// https://www.acmicpc.net/problem/14890

#include <bits/stdc++.h>
using namespace std;

int arr[101][101], vis[101][101];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, l; cin >> n >> l;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	int ans = 2 * n;

	// 가로 확인
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n; j++) {
			// 이전과 현재 높이가 같거나 이미 방문했으면 건너뛰기
			if (arr[i][j - 1] == arr[i][j] || vis[i][j]) continue;
			int chk = 0;

			// 왼쪽이 더 높음
			if (arr[i][j - 1] > arr[i][j]) {
				if (j - 1 + l >= n) chk = 1;
				else {
					for (int k = j - 1 + l; k > j - 1; k--) {
						if (arr[i][k] != arr[i][j] || vis[i][k]) chk = 1;
						vis[i][k] = 1;
					}
				}
			}
			// 오른쪽이 더 높음
			else {
				if (j - l < 0) chk = 1;
				else {
					for (int k = j - l; k < j; k++) {
						if (arr[i][k] != arr[i][j - 1] || vis[i][k]) chk = 1;
						vis[i][k] = 1;
					}
				}
			}
			if (chk || abs(arr[i][j - 1] - arr[i][j]) > 1) {
				ans--;
				break;
			}
		}
	}
	for (int i = 0; i < n; i++)
		fill(vis[i], vis[i] + n, 0);

	// 세로 확인
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (vis[j][i] || arr[j - 1][i] == arr[j][i]) continue;
			int chk = 0;
			if (arr[j - 1][i] > arr[j][i]) {
				if (j - 1 + l >= n) chk = 1;
				else {
					for (int k = j - 1 + l; k > j - 1; k--) {
						if (arr[k][i] != arr[j][i] || vis[k][i]) chk = 1;
						vis[k][i] = 1;
					}
				}
			}
			else {
				if (j - l < 0) chk = 1;
				else {
					for (int k = j - l; k < j; k++) {
						if (arr[k][i] != arr[j - 1][i] || vis[k][i]) chk = 1;
						vis[k][i] = 1;
					}
				}
			}
			if (chk || abs(arr[j - 1][i] - arr[j][i]) > 1) {
				ans--;
				break;
			}
		}
	}
	cout << ans;
}
