#include <bits/stdc++.h>
using namespace std;

void solve(int cur, vector<int>& vis, vector<vector<int> >& adj) {
	for (auto nxt : adj[cur]) {
		if (vis[nxt] >= vis[cur] + 1) continue;
		vis[nxt] = vis[cur] + 1;
		solve(nxt, vis, adj);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	vector<int> vis(n + 1, 1);
	vector<vector<int> > adj(n + 1);
	while (m--) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
	}
	for (int i = 1; i <= n; i++) {
		solve(i, vis, adj);
	}
	for (int i = 1; i <= n; i++) {
		cout << vis[i] << " ";
	}
}