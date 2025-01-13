#include <bits/stdc++.h>
using namespace std;

int v, e, numCnt;
int vis[10005];
vector<pair<int, int> > vertexV;
vector<int> adj[10005], rAdj[10005];
vector<vector<int> > sccV;

bool cmp(pair<int, int>& p1, pair<int, int>& p2) {
	return p1.first > p2.first;
}

void dfs1(int cur) {
	for (const auto& nxt : adj[cur]) {
		if (vis[nxt]) continue;
		vis[nxt] = 1;
		dfs1(nxt);
	}
	vertexV[numCnt] = { numCnt + 1, cur };
	numCnt++;
}

void dfs2(int cur, vector<int>& scc) {
	for (const auto& nxt : rAdj[cur]) {
		if (vis[nxt]) continue;
		vis[nxt] = 1;
		dfs2(nxt, scc);
	}
	scc.push_back(cur);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> v >> e;
	vertexV.resize(v);
	while (e--) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		rAdj[b].push_back(a);
	}

	for (int i = 1; i <= v; i++) {
		if (vis[i]) continue;
		vis[i] = 1;
		dfs1(i);
	}
	
	for (int i = 1; i <= v; i++) vis[i] = 0;
	sort(vertexV.begin(), vertexV.end(), cmp);
	for (int i = 0; i < v; i++) {
		int cur = vertexV[i].second;
		if (vis[cur]) continue;
		vis[cur] = 1;
		vector<int> subScc;
		dfs2(cur, subScc);
		sort(subScc.begin(), subScc.end());
		sccV.push_back(subScc);
	}
	sort(sccV.begin(), sccV.end(), [](const vector<int>& a, const vector<int>& b) {
		return a[0] < b[0];
	});

	cout << sccV.size() << "\n";
	for (const auto& curScc : sccV) {
		for (int num : curScc) {
			cout << num << " ";
		}
		cout << "-1\n";
	}
}