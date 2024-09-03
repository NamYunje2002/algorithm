#include <bits/stdc++.h>
using namespace std;

#define INF 2e9 + 2
#define X first
#define Y second

int n, m, st, en;
int dist[1005], seq[1005];
stack<int> stck;
vector<pair<int, int> > adj[1005];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    fill(dist, dist+1005, INF);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({c, b});
    }
    cin >> st >> en;
    dist[st] = 0;
    pq.push({ dist[st], st });
    while(!pq.empty()) {
        pair<int, int> cur = pq.top(); pq.pop();
        if (dist[cur.Y] != cur.X) continue;
        for (auto nxt : adj[cur.Y]) {
            if (dist[nxt.Y] <= dist[cur.Y] + nxt.X) continue;
            dist[nxt.Y] = dist[cur.Y] + nxt.X;
            pq.push({ dist[nxt.Y], nxt.Y });
            seq[nxt.Y] = cur.Y;
        }
    }
    stck.push(en);
    int cur = en;
    while(1) {
        int pre = seq[cur];
        stck.push(pre);
        if(pre == st) break;
        cur = pre;
    }
    cout << dist[en] << "\n" << stck.size() << "\n";
    while(!stck.empty()) {
        cout << stck.top() << " ";
        stck.pop();
    }
}