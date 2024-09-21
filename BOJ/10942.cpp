#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[2005];
int dp[2005][2005];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];

    for (int i = n; i >= 1; i--) {
        dp[i][i] = 1;
        for (int j = i+1; j <= n; j++) {
            if (j == i+1) {
                if (arr[i] == arr[j]) dp[i][j] = 1;
                continue;
            }
            if (dp[i+1][j-1] && arr[i] == arr[j]) dp[i][j] = 1;
        }
    }

    cin >> m;
    while (m--) {
        int s, e; cin >> s >> e;
        cout << dp[s][e] << "\n";
    }
}