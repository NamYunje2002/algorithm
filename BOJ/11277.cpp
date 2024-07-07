#include <bits/stdc++.h>
using namespace std;

int n, m, ans; 
int v[25];
int arr[105][2];

void solve(int k) {
    if(k == n+1) {
        int rsl = 0;
        for(int i = 0; i < m; i++) {
            int x = v[abs(arr[i][0])], y = v[abs(arr[i][1])];
            if(arr[i][0] < 0) x = !x;
            if(arr[i][1] < 0) y = !y;
            int cur = x||y;
            if(i == 0) rsl = cur;
            else rsl = rsl && cur;
        }
        if(rsl) ans = 1;
        return;
    }
    for(int i = 0; i < 2; i++) {
        v[k] = i;
        solve(k+1);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++) cin >> arr[i][0] >> arr[i][1];
    solve(1);
    cout << ans;
}