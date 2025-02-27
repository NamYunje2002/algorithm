#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

void dfs(int cx, int cy, int tx, int ty, int& cnt, vector<vector<int> >& vis) {
	if (cx == tx && cy == ty) {
		cnt++;
		return;
	}
	if (cy + 1 <= ty && !vis[cx][cy + 1]) {
		vis[cx][cy + 1] = 1;
		dfs(cx, cy + 1, tx, ty, cnt, vis);
		vis[cx][cy + 1] = 0;
	}
	if (cx + 1 <= tx && !vis[cx + 1][cy]) {
		vis[cx + 1][cy] = 1;
		dfs(cx + 1, cy, tx, ty, cnt, vis);
		vis[cx + 1][cy] = 0;
	}
}

int main() {
	int n, m, k; cin >> n >> m >> k;

	vector<vector<int> > board(n, vector<int>(m, 0));
	vector<vector<int> > vis(n, vector<int>(m, 0));

	if (k == 0) {
		int ans = 0;
		vis[0][0] = 1;
		dfs(0, 0, n - 1, m - 1, ans, vis);
		cout << ans;
	}
	else {
		int a = 0, b = 0;
		int mx = (k - 1) / m;
		int my = (k - 1) % m;
		
		vis[0][0] = 1;
		dfs(0, 0, mx, my, a, vis);

		vis[mx][my] = 1;
		dfs(mx, my, n - 1, m - 1, b, vis);
		cout << a * b;
	}
}