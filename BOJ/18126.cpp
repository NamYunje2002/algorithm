#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define X first
#define Y second

int n;
ll ans;
ll vis[5005];
queue<int> q;
vector<pair<int, int> > adj[5005];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n-1; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    vis[1] = 0;
    q.push(1);
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(auto nxt : adj[cur]) {
            if(vis[nxt.X]) continue;
            vis[nxt.X] = vis[cur] + nxt.Y;
            q.push(nxt.X);
        }
    }
    for(int i = 1; i <= n; i++) ans = max(ans, vis[i]);
    cout << ans;
}