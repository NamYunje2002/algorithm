#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
int arr[205][205];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    while(m--) {
        int a, b; cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = i+1; j <= n; j++) {
            if(arr[i][j] || arr[j][i]) continue;
            for(int k = j+1; k <= n; k++) {
                if(arr[i][k] || arr[k][i] || arr[j][k] || arr[k][j]) continue;
                ans++;
            }
        }
    }
    cout << ans;
}