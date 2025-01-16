#include <bits/stdc++.h>
using namespace std;

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    while (1) {
        int r, c; cin >> r >> c;
        if (r == 0 && c == 0) break;
        vector<string> board(r);
        for (int i = 0; i < r; i++) cin >> board[i];
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (board[i][j] == '.') {
                    int cnt = 0;
                    for (int k = 0; k < 8; k++) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                        if (board[nx][ny] == '*') cnt++;
                    }
                    cout << cnt;
                } else {
                    cout << '*';
                }
            }
            cout << "\n";
        }
    }
}