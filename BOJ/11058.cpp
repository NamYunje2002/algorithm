#include <bits/stdc++.h>
using namespace std;

int dp[101];

int main() {
    int n; cin >> n;
    for (int i = 1; i <= 6; i++) dp[i] = i;
    
    cout << dp[n];
}