#include <bits/stdc++.h>
using namespace std;

int n, mx, mn;
int arr[1002], dp[1002];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) {
        mx = mn = arr[i];
        for (int j = i; j >= 0; j--) {
            mx = max(mx, arr[j]);
            mn = min(mn, arr[j]);
            dp[i + 1] = max(dp[i + 1], dp[j] + mx - mn);
        }
    }
    cout << dp[n];
}