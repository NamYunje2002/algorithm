#include <bits/stdc++.h>
using namespace std;

int n, m;
int deg[1002], ans[1002];
vector<int> adj[1002];
queue<int> q;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x; cin >> x;
        vector<int> v(x);
        for(int j = 0; j < x; j++) cin >> v[j];
        for(int j = 0; j < x - 1; j++) {
            adj[v[j]].push_back(v[j+1]);
            deg[v[j+1]]++;
        }
    }
    for(int i = 1; i <= n; i++) if(!deg[i]) q.push(i);
    int cnt = 0;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        ans[cnt++] = cur;
        for(int i = 0; i < (int)adj[cur].size(); i++) {
            int nxt = adj[cur][i];
            deg[nxt]--;
            if(deg[nxt] == 0) q.push(nxt);
        }
    }
    if(cnt != n) cout << 0;
    else for(int i = 0; i < cnt; i++) cout << ans[i] << '\n';
}