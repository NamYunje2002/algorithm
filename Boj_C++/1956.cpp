#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int ans = INF;
int dist[405][405];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int v, e; cin >> v >> e;
    for(int i = 0; i <= v; i++) {
        for(int j = 0; j <= v; j++) {
            dist[i][j] = INF;
        }
    }
    for(int i = 0; i < e; i++) {
        int a, b, c; cin >> a >> b >> c;
        dist[a][b] = c;
    }
    for(int i = 0; i <= v; i++) dist[i][i] = 0;
    for(int k = 1; k <= v; k++) {
        for(int i = 1; i <= v; i++) {
            for(int j = 1; j <= v; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
    for(int i = 1; i <= v; i++) {
        for(int j = i+1; j <= v; j++) {
            ans = min(ans, dist[i][j] + dist[j][i]);
        }
    }
    if(ans == INF) cout << -1;
    else cout << ans;
}