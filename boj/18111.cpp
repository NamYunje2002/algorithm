/* https://www.acmicpc.net/problem/18111 */

#include <iostream>

using namespace std;

int n, m, b, t = 100000003, h, g[502][502];

void solve(int time, int height, int inventory) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (g[i][j] > height) {
				time += (g[i][j] - height) * 2;
				inventory += g[i][j] - height;
			}
			else if (g[i][j] < height) {
				time += height - g[i][j];
				inventory -= height - g[i][j];
			}
		}
	}
	if (inventory < 0) return;
	if (time < t) {
		t = time;
		h = height;
	}
	if (time == t && height > h) 
		h = height;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> b;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> g[i][j];
		}
	}
	for (int i = 0; i <= 256; i++) {
		int time = 0, height = i, inventory = b;
		solve(time, height, inventory);
	}
	cout << t << " " << h;
}
