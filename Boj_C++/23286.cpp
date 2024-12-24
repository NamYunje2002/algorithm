#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int n, m, t;
int d[305][305], ans[305][305];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> t;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            d[i][j] = INF;
        }
    }
    while(m--) {
        int u, v, h; cin >> u >> v >> h;
        d[u][v] = min(d[u][v], h);
    }
    for(int i = 1; i <= n; i++) d[i][i] = 0;
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                d[i][j] = min(d[i][j], max(d[i][k], d[k][j]));
            }
        }
    }    
    while(t--) {
        int s, e; cin >> s >> e;
        cout << (d[s][e] == INF ? -1 : d[s][e]) << '\n';
    }
}