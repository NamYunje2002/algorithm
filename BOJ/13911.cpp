#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

const int INF = 0x3f3f3f3f;

int v, e, m, s, x, y;
int ans = INF;
vector<pair<int, int> > adj[10005];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

void solve(vector<int> &dist) {
    while (!pq.empty()) {
        pair<int, int> cur = pq.top(); pq.pop();
        if (dist[cur.Y] != cur.X) continue;
        for (int i = 0; i < (int)adj[cur.Y].size(); i++) {
            pair<int, int> nxt = adj[cur.Y][i];
            if (dist[nxt.Y] <= dist[cur.Y] + nxt.X) continue;
            dist[nxt.Y] = dist[cur.Y] + nxt.X;
            pq.push({dist[nxt.Y], nxt.Y});
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> v >> e;
    while (e--) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }

    vector<int> dist1(v+1, INF);
    cin >> m >> x;
    for (int i = 0; i < m; i++) {
        int z; cin >> z;
        dist1[z] = 0;
        pq.push({dist1[z], z});
    }
    solve(dist1);

    vector<int> dist2(v+1, INF);
    cin >> s >> y;
    for (int i = 0; i < s; i++) {
        int z; cin >> z;
        dist2[z] = 0;
        pq.push({dist2[z], z});
    }
    solve(dist2);

    for (int i = 0; i <= v; i++) {
        if (dist1[i] && dist2[i] && dist1[i] <= x && dist2[i] <= y) {
            ans = min(ans, dist1[i] + dist2[i]);
        }
    }
    cout << (ans == INF ? -1 : ans);
}