#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int d, k; cin >> d >> k;
    for(int i = k-1; i >= k/2; i--) {
        vector<int> dp(k, -1);
        dp[1] = k, dp[2] = i;
        int cnt = 3;
        while(1) {
            dp[cnt] = dp[cnt-2] - dp[cnt-1];
            if(dp[cnt-1] < dp[cnt] || dp[cnt] == 0) {
                dp[cnt] = -1;
                break;  
            } 
            cnt++;
        }
        if(dp[d] > 0) {
            cout << dp[d] << ' ' << dp[d-1];
            break; 
        }
    }
}