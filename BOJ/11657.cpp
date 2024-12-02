#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define X first
#define Y second

int n, m; 
ll dist[505];
vector<pair<int, int> > adj[505];

int solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k < (int)adj[j].size(); k++) {
                int nxt = adj[j][k].first;
                int cost = adj[j][k].second;
                if (dist[j] != dist[nxt] > cost + dist[j]) {
                    if (i == n - 1) return 0;
                    dist[nxt] = cost + dist[j];
                }
            }
        }
    }
    return 1;
}

int main() {~
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i <= n; i++) dist[i] = INF;
    while (m--) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    dist[1] = 0;
    if (solve()) for (int i = 2; i <= n; i++) cout << (dist[i] == INF ? -1 : dist[i]) << "\n";
    else cout << "-1";
}