// https://www.acmicpc.net/problem/4811

#include <iostream>

using namespace std;
 
int n;
long long dp[32][32];
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i <= 30; i++) {
        for (int j = 0; j <= 30; j++) {
            if (i > j) continue;
            if (i == 0) dp[j][i] = 1;
            else dp[j][i] = dp[j - 1][i] + dp[j][i - 1];
        }
    }
    while (1) {
        cin >> n;
        if (n == 0) break;
        cout << dp[n][n] << "\n";
    }
}
