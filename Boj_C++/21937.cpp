#include <bits/stdc++.h>
using namespace std;

int ans;
int vis[100005];
vector<int> adj[100005];

void solve(int cur) {
    for (const auto& prev : adj[cur]) {
        if (vis[prev]) continue;
        ans++;
        vis[prev] = 1;
        solve(prev);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    while (m--) {
        int a, b; cin >> a >> b;
        adj[b].push_back(a);
    }
    int x; cin >> x;
    vis[x] = 1;
    solve(x);
    cout << ans;

}