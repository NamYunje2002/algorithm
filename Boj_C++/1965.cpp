#include <bits/stdc++.h>
using namespace std;

int ans;
int dp[1005];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        int x = 1;
        for (int j = 0; j < i; j++) {
            if (v[j] < v[i]) x = max(x, dp[j] + 1);
        }
        dp[i] = x;
        ans = max(ans, dp[i]);
    }
    cout << ans;
}