#include <bits/stdc++.h>
using namespace std;

int arr[3][100005], dp[3][100005];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n, ans = 0; cin >> n;
        for(int i = 1; i <= 2; i++) {
            for(int j = 1; j <= n; j++) {
                cin >> arr[i][j];
            }
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= 2; j++) {
                if(j == 1) dp[j][i] = max(dp[j][i-1], dp[j+1][i-1]+arr[j][i]);
                else dp[j][i] = max(dp[j][i-1], dp[j-1][i-1]+arr[j][i]);
                ans = max(ans, dp[j][i]);
            }
        }
        cout << ans << '\n';
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 100005; j++) {
                arr[i][j] = dp[i][j] = 0;
            }
        }       
    }
}