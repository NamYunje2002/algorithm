#include <bits/stdc++.h>
using namespace std;

int r, c, n;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
int bomb[202][202][2];
string board[202];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> r >> c >> n;
    for (int i = 0; i < r; i++) cin >> board[i];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (board[i][j] == 'O') {
                bomb[i][j][0] = 1;
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (0 <= nx && nx < r && 0 <= ny && ny < c) bomb[nx][ny][0] = 1;
                }
            }
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (!bomb[i][j][0]) {
                bomb[i][j][1] = 1;
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (0 <= nx && nx < r && 0 <= ny && ny < c) bomb[nx][ny][1] = 1;
                }
            }
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (n == 1) {
                cout << board[i][j];
            } else if ((n + 4) % 4 == 1) {
                cout << (bomb[i][j][1] ? '.' : 'O');
            } else if ((n + 4) % 4 == 3) {
                cout << (bomb[i][j][0] ? '.' : 'O');
            } else {
                cout << 'O';
            }
        }
        cout << '\n';
    }
}