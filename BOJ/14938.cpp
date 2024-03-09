#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int t[105];
int d[105][105];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, r; cin >> n >> m >> r;
    for(int i = 1; i <= n; i++) cin >> t[i];
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            d[i][j] = INF;
        }
    }
    for(int i = 0; i < r; i++) {
        int a, b, l; cin >> a >> b >> l;
        d[a][b] = min(d[a][b], l);
        d[b][a] = min(d[b][a], l);
    }
    for(int i = 1; i <= n; i++) d[i][i] = 0;
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
            }
        }
    }
    int ans = -1;
    for(int i = 1; i <= n; i++) {
        int tot = 0;
        for(int j = 1; j <= n; j++) {
            if(d[i][j] <= m) tot += t[j];
        }
        ans = max(ans, tot);
    }
    cout << ans;
}