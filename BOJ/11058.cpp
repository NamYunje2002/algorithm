#include <bits/stdc++.h>
using namespace std;

long long dp[101];

int main() {
    int n; cin >> n;
    for (int i = 1; i <= 6; i++) dp[i] = i;
    for (int i = 7; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        for (int j = 1; j <= i - 3; j++) {
            dp[i] = max(dp[i], dp[j] * (i - j - 1));
        }
    }
    cout << dp[n];
}