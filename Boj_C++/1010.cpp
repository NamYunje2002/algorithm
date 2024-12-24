#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[21];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i < 21; i++) dp[i] = dp[i-1] * i;
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        ll ans = 1;
        n = max(n, m-n);
        for(int i = m; i > n; i--) ans *= i;
        cout << ans << ' ';
        cout << ans / dp[m-n] << '\n';
    }
}