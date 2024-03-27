#include <bits/stdc++.h>
using namespace std;

int n, t = 1;
int dp[100005][5], arr[100005][5];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    while(t) {
        cin >> n;
        if(n == 0) break;
        for(int i = 0; i < 100005; i++) for(int j = 0; j < 5; j++) dp[i][j] = 0x3f3f3f3f;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= 3; j++) {
                cin >> arr[i][j];
            }
        }
        dp[1][2] = arr[1][2];
        dp[1][3] = arr[1][2] + arr[1][3];
        for(int i = 2; i <= n; i++) {
            dp[i][1] = min(dp[i-1][1], dp[i-1][2]) + arr[i][1];
            dp[i][2] = min(dp[i][1], min(dp[i-1][1], min(dp[i-1][2], dp[i-1][3]))) + arr[i][2];
            dp[i][3] = min(dp[i][2], min(dp[i-1][2], dp[i-1][3])) + arr[i][3];
        }
        cout << t << ". " << dp[n][2] << '\n';
        t++;
    }
}