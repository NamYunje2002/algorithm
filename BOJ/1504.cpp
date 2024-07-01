#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

const int INF = 0x3f3f3f3f;

int n, e;
int dist[805];
vector<pair<int, int> > adj[805];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq; 

void setDist() {
    while(!pq.empty()) {
        pair<int, int> cur = pq.top(); pq.pop();
        if(dist[cur.Y] != cur.X) continue;
        for(auto nxt : adj[cur.Y]) { 
            if(dist[nxt.Y] <= dist[cur.Y] + nxt.X) continue;
            dist[nxt.Y] = dist[cur.Y] + nxt.X;
            pq.push({dist[nxt.Y], nxt.Y});
        }
    }
}

int solve(int v1, int v2) {
    int rsl = 0;
    fill(dist, dist+805, INF);
    dist[1] = 0;
    pq.push({dist[1], 1});
    setDist();
    if(dist[v1] == INF) return INF;
    rsl += dist[v1];

    fill(dist, dist+805, INF);
    dist[v1] = 0;
    pq.push({dist[v1], v1});
    setDist();
    if(dist[v2] == INF) return INF;
    rsl += dist[v2];
    

    fill(dist, dist+805, INF);
    dist[v2] = 0;
    pq.push({dist[v2], v2});
    setDist();
    if(dist[n] == INF) return INF;
    rsl += dist[n];

    return rsl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> e;
    while(e--) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    int v1, v2; cin >> v1 >> v2;
    
    int ans1 = solve(v1, v2), ans2 = solve(v2, v1);
    if(ans1 == INF && ans2 == INF) cout << -1;
    else cout << min(ans1, ans2);
}