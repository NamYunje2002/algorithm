#include <bits/stdc++.h>
using namespace std;

int n, ans;
int arr[10], c[10], vis[10];

void solve(int k) {
    if(k == n) {
        int rsl = 0;
        for(int i = 0; i < n-1; i++) {
            rsl += abs(c[i]-c[i+1]);
        }
        ans = max(ans, rsl);
        return;
    }
    for(int i = 0; i < n; i++) {
        if(vis[i]) continue;
        c[k] = arr[i];
        vis[i] = 1;
        solve(k+1);
        vis[i] = 0;
    }
}   

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    solve(0);
    cout << ans;
}