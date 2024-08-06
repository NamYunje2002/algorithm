#include <bits/stdc++.h>
using namespace std;

int n;
int T[1500005], P[1500005];
int dp[1500005];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> T[i] >> P[i];
    for(int i = n; i >= 1; i--) {
        if((i-1)+T[i] > n) dp[i] = dp[i+1];
        else dp[i] = max(dp[i+1], dp[i + T[i]] + P[i]);
    }
    cout << dp[1];
}