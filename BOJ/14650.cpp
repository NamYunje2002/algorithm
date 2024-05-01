#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9+9;
ll dp[33335];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    dp[2] = 2;
    for(int i = 3; i < 33335; i++) dp[i] = dp[i-1] * 3 % MOD;
    int n; cin >> n;
    cout << dp[n];
}