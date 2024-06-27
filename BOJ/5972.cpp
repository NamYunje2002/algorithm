#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

#define X first
#define Y second

int n, m;
int d[50005];
vector<pair<int, int> > adj[50005];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    fill(d, d+n+5, INF);
    d[1] = 0;
    pq.push({d[1], 1});
    while(!pq.empty()) {
        pair<int, int> cur = pq.top(); pq.pop();
        if(d[cur.Y] != cur.X) continue;
        for(int i = 0; i < adj[cur.Y].size(); i++) {
            pair<int, int> nxt = adj[cur.Y][i];
            if(d[nxt.Y] <= d[cur.Y]+nxt.X) continue;
            d[nxt.Y] = d[cur.Y]+nxt.X;
            pq.push({d[nxt.Y], nxt.Y});
        }
    }
    cout << d[n];
}