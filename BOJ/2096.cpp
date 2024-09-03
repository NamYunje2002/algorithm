#include <bits/stdc++.h>
using namespace std;

int n, max_ans = -1, min_ans = 1000000;
int max_dp[2][3], min_dp[2][3], cur[3];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> cur[j];
        }
        for (int j = 0; j < 3; j++) {
            max_dp[1][j] = max_dp[0][j] + cur[j];
            min_dp[1][j] = min_dp[0][j] + cur[j];

            if (j == 0) {
                max_dp[1][j] = max(max_dp[1][j], max_dp[0][j+1] + cur[j]);
                min_dp[1][j] = min(min_dp[1][j], min_dp[0][j+1] + cur[j]);
            } else if (j == 2) {
                max_dp[1][j] = max(max_dp[1][j], max_dp[0][j-1] + cur[j]);
                min_dp[1][j] = min(min_dp[1][j], min_dp[0][j-1] + cur[j]);
            } else {
                max_dp[1][j] = max(max_dp[1][j], max(max_dp[0][j+1] + cur[j], max_dp[0][j-1] + cur[j]));
                min_dp[1][j] = min(min_dp[1][j], min(min_dp[0][j+1] + cur[j], min_dp[0][j-1] + cur[j]));
            }
        }
        for (int j = 0; j < 3; j++) {
            max_dp[0][j] = max_dp[1][j];
            min_dp[0][j] = min_dp[1][j];
            cout << min_dp[0][j] << ' ';
        }
        cout << "\n";
    }
    for (int i = 0; i < 3; i++) {
        min_ans = min(min_ans, min_dp[0][i]);
        max_ans = max(max_ans, max_dp[0][i]);
    }
    cout << max_ans << ' ' << min_ans;
}