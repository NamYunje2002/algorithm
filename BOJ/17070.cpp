#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n;
int dx[3] = {0, 1, 1}, dy[3] = {1, 0, 1};
int board[15][15], dp[15][15][3];

int solve(pair<int, int> cur, int dir) {
    if (cur.X == n-1 && cur.Y == n-1) return 1;
    if (dp[cur.X][cur.Y][dir] != -1) return dp[cur.X][cur.Y][dir];
    dp[cur.X][cur.Y][dir] = 0;
    for (int i = 0; i < 3; i++) {
        if (dir == 0 && i == 1) continue;
        if (dir == 1 && i == 0) continue;
         
        int nx = cur.X+dx[i];
        int ny = cur.Y+dy[i];

        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if (board[nx][ny] == 1) continue;
        if (i == 2 && (board[nx-1][ny] == 1 || board[nx][ny-1] == 1)) continue;
        
        dp[cur.X][cur.Y][dir] += solve({nx, ny}, i);
    }
    return dp[cur.X][cur.Y][dir];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = -1;
        }
    }
    cout << solve({0, 1}, 0);
}