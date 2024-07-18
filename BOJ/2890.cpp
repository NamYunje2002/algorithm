#include <bits/stdc++.h>
using namespace std;

int r, c, p[10], ans[10], vis[55];
string arr[55];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> r >> c;    
    for(int i = 0; i < r; i++) {
        cin >> arr[i];
    }
    for(int i = 0; i < r; i++) {
        for(int j = c-1; j >= 0; j--) {
            if('1' <= arr[i][j] && arr[i][j] <= '9') {
                p[arr[i][j]-'0'] = j;
                break;
            }
        }
    }
    for(int i = 1; i < 10; i++) {
        ans[i] = 1;
        for(int j = 1; j < 10; j++) {
            if(p[i] < p[j] && !vis[p[j]]) {
                ans[i]++;
                vis[p[j]] = 1;
            }
        }
        for(int j = 0; j < 55; j++) vis[j] = 0;
    }
    for(int i = 1; i < 10; i++) cout << ans[i] << "\n";
}