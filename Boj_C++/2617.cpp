#include <bits/stdc++.h>
using namespace std;

int bfs(int st, vector<vector<int> > adj, int n) {
	int cnt = 0;
	queue<int> q;
	vector<int> vis(n + 1, 0);
	vis[st] = 1;
	q.push(st);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		cnt++;
		for (const auto& nxt : adj[cur]) {
			if (vis[nxt]) continue;
			vis[nxt] = 1;
			q.push(nxt);
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	vector<int> cntArr(n + 1, -1), rCntArr(n + 1, -1);
	vector<vector<int> > adj(n + 1), rAdj(n + 1);
	while (m--) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		rAdj[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		cntArr[i] = bfs(i, adj, n);
		rCntArr[i] = bfs(i, rAdj, n);
	}
	int ans = 0, k = n / 2 + 1;
	for (int i = 1; i <= n; i++) {
		if ((cntArr[i] - 1) >= k || (rCntArr[i] - 1) >= k) {
			ans++;
		}
	}
	cout << ans;
}