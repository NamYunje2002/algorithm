#include <bits/stdc++.h>
using namespace std;

int ans[5];
string board[505];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int m, n; cin >> m >> n;
    for(int i = 0; i <= 5*m; i++) {
        cin >> board[i];
    }
    for(int i = 1; i < 5*m; i+=5) {
        for(int j = 1; j < 5*n; j+=5) {
            int cnt = 0;
            for(int k = 0; k < 4; k++) {
                if(board[i+k][j] == '*') cnt++;
            }
            ans[cnt]++;
        }
    }
    for(int i = 0; i < 5; i++) cout << ans[i] << ' ';
}