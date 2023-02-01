// https://www.acmicpc.net/problem/1260

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, v, s, e, vis[1001];
vector<int> adj[1001];
queue<int> Q;

void dfs(int k) {
	cout << k << " ";
	for (int i = 0; i < adj[k].size(); i++) {
		if (vis[adj[k][i]]) continue;
		vis[adj[k][i]] = 1;
		dfs(adj[k][i]);
	}
}

void bfs() {
	Q.push(v);
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		cout << cur << " ";
		for (int i = 0; i < adj[cur].size(); i++) {
		if (!vis[adj[cur][i]]) continue;
			vis[adj[cur][i]] = 0;
			Q.push(adj[cur][i]);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> v;
	while (m--) {
		cin >> s >> e;
		adj[s].push_back(e);
		adj[e].push_back(s);
	}
	for (int i = 1; i <= n; i++)
        sort(adj[i].begin(), adj[i].end());
	vis[v] = 1;
	dfs(v);
	cout << "\n";
	vis[v] = 0;
	bfs();
}
