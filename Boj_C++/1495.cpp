#include <bits/stdc++.h>
using namespace std;

int dp[52][1005];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, s, m; cin >> n >> s >> m;
    dp[0][s] = 1;
    for(int i = 0; i < n; i++) {
        int k; cin >> k;
        for(int j = 0; j <= m; j++) {
            if(dp[i][j]) {
                if(j+k <= m) dp[i+1][j+k] = 1;
                if(j-k >= 0) dp[i+1][j-k] = 1;
            }
        }
    }
    int ans = -1;
    for(int i = 0; i <= m; i++) if(dp[n][i]) ans = i;
    cout << ans;
}