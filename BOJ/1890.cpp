#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, ans;
int board[101][101];
ll dp[101][101];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> board[i][j];
    dp[0][0] = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == n-1 && j== n-1) break;
            if(i+board[i][j] < n) dp[i+board[i][j]][j] += dp[i][j];
            if(j+board[i][j] < n) dp[i][j+board[i][j]] += dp[i][j];
        }
    }
    cout << dp[n-1][n-1];
}