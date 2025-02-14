#include <bits/stdc++.h>
using namespace std;

int board[1005][1005], dp[1005][1005][3];

const int MAX = 1000000;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> board[i][j];
        }
    }

    for (int j = 0; j <= n + 1; j++) {
        for (int k = 0; k < 3; k++) {
            dp[j][0][k] = dp[j][m + 1][k] = MAX;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = board[i][j];

            dp[i][j][0] += min(dp[i - 1][j - 1][1], dp[i - 1][j - 1][2]);
            dp[i][j][1] += min(dp[i - 1][j][0], dp[i - 1][j][2]);
            dp[i][j][2] += min(dp[i - 1][j + 1][1], dp[i - 1][j + 1][0]);
        }
    }

    int ans = MAX;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < 3; j++) {
            ans = min(ans, dp[n][i][j]);
        }
    }
    cout << ans;
}