#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int n, m; 
int g[255][255];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            g[i][j] = INF;
        }    
    }
    for(int i = 0; i < m; i++) {
        int u, v, b; cin >> u >> v >> b;
        g[u][v] = 0;
        if(b) g[v][u] = 0;
        else g[v][u] = 1;
    }
    for(int i = 1; i <= n; i++) g[i][i] = 0;
    for(int z = 1; z <= n; z++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                g[i][j] = min(g[i][j], g[i][z]+g[z][j]);
            }    
        }
    }
    int k; cin >> k;
    for(int i = 0; i < k; i++) {
        int s, e; cin >> s >> e;
        cout << g[s][e] << '\n';
    }
}