#include <bits/stdc++.h>
using namespace std;

int n, k, ans = 0x7f7f7f7f;
int arr[15], vis[15]; 
int t[15][15];

void FindMin(int p, int cnt) {
    if(cnt == n) {
        int sum = 0;
        for(int i = 0; i < n; i++) sum += arr[i];
        ans = min(ans, sum);
        return;
    }
    for(int i = 0; i < n; i++) {
        if(vis[i]) continue;
        vis[i] = 1;
        arr[cnt] = t[p][i];
        FindMin(i, cnt+1);
        arr[cnt] = 0;
        vis[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> t[i][j];
        }
    }
    for(int z = 0; z < n; z++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                t[i][j] = min(t[i][j], t[i][z]+t[z][j]);
            }
        }
    }
    vis[k] = 1;
    FindMin(k, 1);
    cout << ans;
}