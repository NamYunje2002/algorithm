#include <bits/stdc++.h>
using namespace std;

int maxCnt;
int arr[505], dp[505];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        arr[a] = b;
    }
    for (int i = 1; i <= 500; i++) {
        if (!arr[i]) continue;
        dp[i] = 1;
        for (int j = 1; j < i; j++) {
            if (j < i && arr[j] > arr[i]) continue;
            if (j > i && arr[j] < arr[i]) continue;
            dp[i] = max(dp[i], dp[j] + 1);
            maxCnt = max(maxCnt, dp[i]);
        }
    }
    cout << n - maxCnt;
}