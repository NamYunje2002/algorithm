#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[91];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    dp[1] = 1;
    for(int i = 2; i < 92; i++) dp[i] = dp[i-1]+dp[i-2];
    int n; cin >> n;
    cout << dp[n];
}