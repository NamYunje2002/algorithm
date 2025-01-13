#include <bits/stdc++.h>
using namespace std;

int numCnt;

bool cmp(pair<int, int>& p1, pair<int, int>& p2) {
	return p1.first > p2.first;
}

void dfs1(int cur, vector<vector<int> >& adj, vector<pair<int, int> >& cntV, vector<int>& vis) {
	for (const auto& nxt : adj[cur]) {
		if (vis[nxt]) continue;
		vis[nxt] = 1;
		dfs1(nxt, adj, cntV, vis);
	}
	cntV[numCnt] = { numCnt + 1, cur };
	numCnt++;
}

void dfs2(int cur, vector<vector<int> >& adj, vector<int>& vis, const int sccCnt, bool& flag) {
	for (const auto& nxt : adj[cur]) {
		if (vis[nxt]) {
			if (vis[nxt] != sccCnt) flag = 1;
			continue;
		}
		vis[nxt] = sccCnt;
		dfs2(nxt, adj, vis, sccCnt, flag);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		vector<int> vis(n + 1, 0);
		vector<vector<int> > adj(n + 1);
		vector<vector<int> > rAdj(n + 1);
		vector<pair<int, int> > cntV(n);
		while (m--) {
			int x, y; cin >> x >> y;
			adj[x].push_back(y);
			rAdj[y].push_back(x);
		}
		for (int i = 1; i <= n; i++) {
			if (vis[i]) continue;
			vis[i] = 1;
			dfs1(i, adj, cntV, vis);
		}

		
		sort(cntV.begin(), cntV.end(), cmp);
		int sccCnt = 0, minusCnt = 0;
		for (int i = 1; i <= n; i++) vis[i] = 0;
		
		for (int i = 0; i < n; i++) {
			int cur = cntV[i].second;
			if (vis[cur]) continue;
			sccCnt++;
			vis[cur] = sccCnt;
			bool flag = false;
			dfs2(cur, rAdj, vis, sccCnt, flag);
			if (flag) minusCnt++;
		}
		cout << sccCnt - minusCnt << "\n";
		numCnt = 0;
	}
}