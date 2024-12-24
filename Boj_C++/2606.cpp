// https://www.acmicpc.net/problem/2606

#include <iostream>
#include <vector>

using namespace std;

int n, m, u, v, ans, vis[101];
vector<int> adj[101];

void dfs(int k) {
	vis[k] = 1;
	for (int i = 0; i < adj[k].size(); i++) {
		if (vis[adj[k][i]]) continue;
		dfs(adj[k][i]);
		ans++;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	while (m--) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	cout << ans;
}
