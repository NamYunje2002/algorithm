#include <bits/stdc++.h>
using namespace std;

int vis[101];
vector<int> adj[5002];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    int mnCnt = 0x7f7f7f7f, ans;
    while(m--) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= n; j++) vis[j] = -1;
        int cnt = 0;
        vis[i] = 0;
        queue<int> q;
        q.push(i);
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            for(int j = 0; j < (int)adj[cur].size(); j++) {
                int nxt = adj[cur][j];
                if(vis[nxt] != -1) continue;
                vis[nxt] = vis[cur] + 1;
                q.push(nxt);
            }
        }
        cout << i << " : ";
        for(int j = 1; j <= n; j++) {
            cout << vis[j] << ' ';
            if(i==j)continue;
            cnt+= vis[j];
        }
        cout << "cnt : " << cnt << "\n";
        if(cnt < mnCnt) {
            ans = i;
            mnCnt = cnt;
        }
    }
    cout << ans;
}