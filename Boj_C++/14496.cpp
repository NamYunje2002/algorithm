#include <bits/stdc++.h>
using namespace std;

int vis[1001];
vector<int> adj[1001];

int main() {
    fill(vis, vis+1001, -1);
    int a, b; cin >> a >> b;
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    queue<int> q;
    q.push(a);
    vis[a] = 0;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(int i = 0; i < (int)adj[cur].size(); i++) {
            int nxt = adj[cur][i];
            if(vis[nxt] > -1) continue;
            vis[nxt] = vis[cur] + 1;
            q.push(nxt);
        }
    }
    cout << vis[b];
}   