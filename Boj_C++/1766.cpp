#include <bits/stdc++.h>
using namespace std;

int deg[32001];
vector<int> g[32001];
priority_queue<int, vector<int>, greater<int> > pq;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    while(m--) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        deg[b]++;
    }
    for(int i = 1; i <= n; i++) if(!deg[i]) pq.push(i);
    while(!pq.empty()) {
        int cur = pq.top(); pq.pop();
        cout << cur << ' ';
        for(int nxt : g[cur]) {
            deg[nxt]--;
            if(!deg[nxt]) pq.push(nxt);
        }
    }
}