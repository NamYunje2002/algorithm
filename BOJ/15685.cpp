#include <bits/stdc++.h>
using namespace std;

int ans, p2[11];
int dx[4] = { 0, -1, 0, 1 }, dy[4] = { 1, 0, -1, 0 };
int board[1025][1025];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;

	// 2^n 배열 생성
	p2[0] = 1;
	for (int i = 1; i < 11; i++) p2[i] = p2[i - 1] * 2;

	while (n--) {
		int x, y, d, g; cin >> y >> x >> d >> g;
		int dir[1025];
		board[x][y] = 1;
		dir[0] = d;
		dir[1] = (d + 1) % 4;

		// 2세대부터 g세대까지
		for (int i = 2; i <= g; i++) {

			// (i-1)세대의 뒤쪽 절반을 i세대의 뒤쪽 절반의 뒤쪽 절반에 저장
			int idx = p2[i] - 1;
			for (int j = p2[i] / 2 - 1; j >= p2[i - 1] / 2; j--) {
				dir[idx--] = dir[j];
			}

			// (i-1)세대의 앞쪽 절반을 회전 후, i세대의 뒤쪽 절반의 앞쪽 절반에 저장
			idx = p2[i] / 2;
			for (int j = 0; j < p2[i - 1] / 2; j++) {
				dir[idx++] = (dir[j] + 2) % 4;
			}
		}
		// 위치 정보대로 찍어주기
		for (int i = 0; i < p2[g]; i++) {
			x += dx[dir[i]];
			y += dy[dir[i]];
			board[x][y] = 1;
		}
	}
	// 1×1인 정사각형의 네 꼭짓점이 모두 드래곤 커브의 일부인 것의 개수 세기
	for (int i = 0; i < 1025; i++) {
		for (int j = 0; j < 1025; j++) {
			if (board[i][j] == 1 && board[i + 1][j] == 1 && board[i][j + 1] == 1 && board[i + 1][j + 1] == 1) {
				ans++;
			}
		}
	}
	cout << ans;
}
