#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

#define MX 500005

int n, m, s, p;
int nodeId;
int atm[MX];
int isFinished[MX];
int idArr[MX];
int sccId[MX];
int deg[MX];
int dp[MX];
int ans;
stack<int> st;
queue<int> q;
set<pair<int, int> > edgeSet;
vector<int> adj[MX];
vector<int> newAdj[MX];
vector<pair<int, vector<int> > > sccVector;

int buildScc(int cur) {
	int p = idArr[cur] = ++nodeId;
	st.push(cur);
	for (const auto& nxt : adj[cur]) {
		if (!idArr[nxt]) p = min(p, buildScc(nxt));
		else if (!isFinished[nxt]) p = min(p, idArr[nxt]);
	}
	if (p == idArr[cur]) {
		int sum = 0;
		vector<int> scc;
		while (!st.empty()) {
			int t = st.top(); st.pop();
			scc.push_back(t);
			isFinished[t] = 1;
			sum += atm[t];
			sccId[t] = (int)sccVector.size();
			if (t == cur) break;
		}
		sccVector.push_back({ sum, scc });
	}
	return p;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	fill(sccId, sccId + MX, -1);

	cin >> n >> m;
	while (m--) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
	}
	for (int i = 1; i <= n; i++) cin >> atm[i];
	cin >> s >> p;
	buildScc(s);

	for (int i = 1; i <= n; i++) {
		if (sccId[i] == -1) continue;
		for (const auto& j : adj[i]) {
			if (sccId[j] == -1) continue;
			if (sccId[j] != sccId[i]) {
				if (edgeSet.find({ sccId[i], sccId[j] }) == edgeSet.end()) {
					edgeSet.insert({ sccId[i], sccId[j] });
					newAdj[sccId[i]].push_back(sccId[j]);
					deg[sccId[j]]++;
				}
			}
		}
	}

	dp[sccId[s]] = sccVector[sccId[s]].X;
	q.push(sccId[s]);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (const auto& nxt : newAdj[cur]) {
			dp[nxt] = max(dp[nxt], sccVector[nxt].X + dp[cur]);
			deg[nxt]--;
			if (deg[nxt] == 0) q.push(nxt);
		}
	}

	while (p--) {
		int r; cin >> r;
		if (sccId[r] == -1) continue;
		ans = max(ans, dp[sccId[r]]);
	}
	cout << ans;
}