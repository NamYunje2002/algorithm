#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[65][12], ans[65];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    dp[1][10] = 1;
    for(int i = 2; i <= 64; i++) {
        for(int j = 10; j >= 1; j--) {
            dp[i][j] = dp[i-1][j] + dp[i][j+1];
        }
    }

    for(int i = 1; i <= 64; i++) {
        for(int j = 1; j <= 10; j++) {
            ans[i] += dp[i][j] * j;
        }
    }

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        cout << ans[n] << '\n';
    }
}