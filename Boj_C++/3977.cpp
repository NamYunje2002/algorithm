#include <bits/stdc++.h>
using namespace std;

int id;
stack<int> st;

int solve(int cur, vector<int>& idV, vector<int>& finishedV, vector<vector<int> >& adj, vector<vector<int> >& SCC, vector<int>& sccV) {
    int p = idV[cur] = ++id;
    st.push(cur);   
    for (const auto& nxt : adj[cur]) {
        if (!idV[nxt]) {
            p = min(p, solve(nxt, idV, finishedV, adj, SCC, sccV));
        } else if (!finishedV[nxt]) {
            p = min(p, idV[nxt]);
        }
    }
    if (p == idV[cur]) {
        vector<int> scc;
        while (!st.empty()) {
            int t = st.top(); st.pop();
            scc.push_back(t);
            finishedV[t] = 1;
            sccV[t] = SCC.size();
            if (cur == t) break;    
        }
        SCC.push_back(scc);
    }
    return p;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        id = 0;
        vector<int> idV(n, 0);
        vector<int> finishedV(n, 0);
        vector<int> sccV(n, -1);
        vector<vector<int> > SCC;
        vector<vector<int> > adj(n);
        while (m--) {
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
        }
        for (int i = 0; i < n; i++) {
            if (!idV[i]) solve(i, idV, finishedV, adj, SCC, sccV);
        }
        vector<int> deg(SCC.size(), 0);
        for (int i = 0; i < n; i++) {
            for (const auto& j : adj[i]) {
                if (sccV[i] != sccV[j]) {
                    deg[sccV[j]]++;
                }
            }
        }
        int ansCnt = 0;
        vector<int> ans;
        vector<int> vis(SCC.size(), 0);
        for (int i = 0; i < n; i++) {
            if (deg[sccV[i]] == 0) {
                if (!vis[sccV[i]]) ansCnt++;
                vis[sccV[i]] = 1;
                ans.push_back(i);
            }
        }
        if (ansCnt > 1) cout << "Confused\n";
        else {
            for (const auto& i : ans) {
                cout << i << "\n";
            }
        }
        cout << "\n";
    }
}