#include <bits/stdc++.h>
using namespace std;

int n, m;
int vis[2002];
vector<int> adj[2002];

void dfs(int k, int cnt) {
    if(cnt == 5) {
        cout << "1";
        exit(0);
    }
    for(int i = 0; i < (int)adj[k].size(); i++) {
        int nxt = adj[k][i];
        if(vis[nxt]) continue;
        vis[nxt] = 1;
        dfs(nxt, cnt + 1);
        vis[nxt] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 0; i < n; i++) {
        vis[i] = 1;
        dfs(i, 1);
        fill(vis, vis+2002, 0);
    }
    cout << "0";
}