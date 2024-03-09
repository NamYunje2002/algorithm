#include <bits/stdc++.h>
using namespace std;

int vis[300001];
vector<int> g[300001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    fill(vis, vis+300001, -1);
    int n, m, k, x; cin >> n >> m >> k >> x;
    while(m--) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
    }
    queue<int> q;
    q.push(x);
    vis[x] = 0;
    int chk = 0;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(int i = 0; i < (int)g[cur].size(); i++) {
            int nxt = g[cur][i];
            if(vis[nxt] == -1) {
                vis[nxt] = vis[cur]+1;
                q.push(nxt);
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        if(vis[i] == k) {
            chk = 1;
            cout << i << "\n";
        }
    }
    if(!chk) cout << "-1";
}