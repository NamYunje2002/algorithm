#include <bits/stdc++.h>
using namespace std;

int a;
double b;
int c[5002], p[5002], dp[10002];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    while(1) {
        cin >> a >> b;
        if(a == 0) break;
        int n = a, m = b*100+0.5;
        for(int i = 1; i <= n; i++) {
            cin >> a >> b;
            c[i] = a;
            p[i] = b*100+0.5;
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(j >= p[i]) dp[j] = max(dp[j], dp[j-p[i]] + c[i]);
            }
        }
        cout << dp[m] << '\n';
    }  
}