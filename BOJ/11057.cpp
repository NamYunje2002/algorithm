#include <bits/stdc++.h>
using namespace std;

int dp[1001][12], ans[1001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    dp[1][10] = 1;
    for(int i = 2; i <= 1000; i++) {
        for(int j = 10; j >= 1; j--) {
            dp[i][j] = (dp[i-1][j] + dp[i][j+1]) % 10007;
        }
    }
    
    for(int i = 1; i <= 1000; i++) {
        for(int j = 1; j <= 10; j++) {
            ans[i] += dp[i][j] * j % 10007;
        }
    }
    cout << ans[n] % 10007;
}