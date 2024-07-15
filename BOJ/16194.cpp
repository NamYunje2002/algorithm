#include <bits/stdc++.h>
using namespace std;

int arr[1005], dp[1005];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    for(int i = 1; i <= n; i++) {
        dp[i] = arr[i];
        for(int j = 1; j < i; j++) {
            dp[i] = min(dp[i], dp[j]+dp[i-j]);
        }
    }
    cout << dp[n];
}