#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
string board[15], ans[15];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int r, c; cin >> r >> c;
    for(int i = 0; i < r; i++) {
        cin >> board[i];
        ans[i] = board[i];
    }
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            int cnt = 0;
            for(int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(nx < 0 || nx >= r || ny < 0 || ny >= c || board[nx][ny] == '.') cnt++;
            }
            if(cnt > 2) ans[i][j] = '.';
        }
    }
    int stX = -1, stY = -1, enX = -1, enY = -1;
    for(int i = 0; i < r; i++) {
        int chk = 0;
        for(int j = 0; j < c; j++) {
            if(ans[i][j] == 'X') chk = 1;
        }
        if(chk) {
            if(stX == -1) stX = i;
            else enX = i;
        }
    }
    if(enX == -1) enX = stX;

    for(int i = 0; i < c; i++) {
        int chk = 0;
        for(int j = 0; j < r; j++) {
            if(ans[j][i] == 'X') chk = 1;
        }
        if(chk) {
            if(stY == -1) stY = i;
            else enY = i;
        }
    }
    if(enY == -1) enY = stY;
    for(int i = stX; i <= enX; i++) {
        for(int j = stY; j <= enY; j++) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
}