#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define X first
#define Y second

ll v, ans;
ll dist[100005];
vector<pair<int, int> > adj[100005];

void dfs(int k) {
    for(auto nxt : adj[k]) {
        if(dist[nxt.X] != -1) continue;
        dist[nxt.X] = dist[k] + nxt.Y;
        dfs(nxt.X);
    }

}

int main() {
    fill(dist, dist+100005, -1);
    cin >> v;
    for(int i = 1; i <= v; i++) {
        int a; cin >> a;
        while(1) {
            int b; cin >> b;
            if(b == -1) break;
            int c; cin >> c;
            adj[a].push_back({b, c});
            adj[b].push_back({a, c});
        }
    }
    dist[1] = 0;
    dfs(1);
    int mxV = 0;
    for(int i = 1; i <= v; i++) {
        if(dist[i] > dist[mxV]) mxV = i;
    }
    fill(dist, dist+100005, -1);
    dist[mxV] = 0;
    dfs(mxV);
    for(int i = 1; i <= v; i++) {
        ans = max(ans, dist[i]);
    }
    cout << ans;
}