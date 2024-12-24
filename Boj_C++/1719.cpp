#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int d[205][205], nxt[205][205];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            d[i][j] = INF;
        }    
    }
    for(int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        if(c < d[a][b]) {
            d[a][b] = c;
            nxt[a][b] = b;
        }
        if(c < d[b][a]) {
            d[b][a] = c;
            nxt[b][a] = a;
        }
    }
    for(int i = 1; i <= n; i++) d[i][i] = 0;
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(d[i][k]+d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k]+d[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i==j) cout << "- ";
            else cout << nxt[i][j] << " ";
        }    
        cout << "\n";
    }
}