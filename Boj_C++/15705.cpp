#include <bits/stdc++.h>

using namespace std;

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
string arr[101];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j  = 0; j < m; j++) {
            if(arr[i][j] != s[0]) continue;
            for(int k = 0; k < 8; k++) {
                int isWrong = 0;
                int x = i, y = j;
                for(int l = 1; l < (int)s.size(); l++) {
                    x += dx[k];
                    y += dy[k];
                    if(x < 0 || x >= n || y < 0 || y >= m) {
                        isWrong = 1;
                        break;
                    }
                    if(arr[x][y] != s[l]) {
                        isWrong = 1;
                        break;
                    }
                }
                if(!isWrong) ans = 1;
            }
        }
    }
    cout << ans;
}