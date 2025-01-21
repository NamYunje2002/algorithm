#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int dp[1005][1005];

int main() {
    dp[0][0] = 1;
    for (int i = 1; i < 1005; i++) {
        for (int j = 1; j < 1005; j++) {
            dp[i][j] = ((dp[i][j - 1] + dp[i - 1][j]) % MOD + dp[i - 1][j - 1]) % MOD;
        }
    }
    int n, m; cin >> n >> m;
    cout << dp[n][m];
}