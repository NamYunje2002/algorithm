#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

const int INF = 0x3f3f3f;
priority_queue<int, vector<int>, greater<int> > ANS_PQ;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > PQ;

void Dijkstra(vector<pair<int, int> > *adj, vector<int> &dist, int st) {
    dist[st] = 0;
    PQ.push({ dist[st], st });
    while (!PQ.empty()) {
        pair<int, int> cur = PQ.top(); PQ.pop();
        if (dist[cur.Y] != cur.X) { continue; }
        for (auto nxt : adj[cur.Y]) {
            if (dist[nxt.Y] <= dist[cur.Y] + nxt.X) { continue; }
            dist[nxt.Y] = dist[cur.Y] + nxt.X;
            PQ.push({ dist[nxt.Y], nxt.Y });
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int TC; cin >> TC;
    while (TC--) {
        int n, m, t; cin >> n >> m >> t;
        int s, g, h; cin >> s >> g >> h;
        int nd = 0;
        vector<int> distS(n+1, INF);
        vector<int> distG(n+1, INF);
        vector<int> distH(n+1, INF);
        vector<int> candidate(t);
        vector<pair<int, int> > * adj = new vector<pair<int, int> >[n+1];
        while (m--) {
            int a, b, d; cin >> a >> b >> d;
            adj[a].push_back({d, b});
            adj[b].push_back({d, a});
            if ((a == g && b == h) || (a == h && b == g)) { nd = d; }
        }
        for (int i = 0; i < t; i++) { cin >> candidate[i]; }
        Dijkstra(adj, distS, s);
        Dijkstra(adj, distG, g);
        Dijkstra(adj, distH, h);
        for (int i = 0; i < t; i++) {
            int minDist = min(distS[g] + distH[candidate[i]] + nd, distS[h] + distG[candidate[i]] + nd);
            if (distS[candidate[i]] >= minDist) { PQ.push({ candidate[i], minDist }); }
        }
        while (!PQ.empty()) {
            cout << PQ.top().X << ' ';
            PQ.pop();
        }
        cout << '\n';
        delete[] adj;

    }
}