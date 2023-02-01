// https://www.acmicpc.net/problem/11725

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, u, v, ans[100001];
vector<int> adj[100001];
queue<int> Q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i < n; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	Q.push(1);
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		for (int i = 0; i < adj[cur].size(); i++) {
			if (ans[adj[cur][i]]) continue;
			ans[adj[cur][i]] = cur;
			Q.push(adj[cur][i]);
		}
	}
	for (int i = 2; i <= n; i++)
		cout << ans[i] << "\n";
}
