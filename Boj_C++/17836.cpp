#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m, t, ans = -1;
int sx = -1, sy = -1;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int board[105][105], vis[105][105];

void bfs(pair<int, int> st, int isS) {
    queue<pair<int, int> > Q;
    Q.push(st);
    while (!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        if (board[cur.X][cur.Y] == 2) {
            sx = cur.X;
            sy = cur.Y;
        }
        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (!isS && board[nx][ny] == 1) continue;
            if (vis[nx][ny] != -1 && vis[nx][ny] <= vis[cur.X][cur.Y] + 1) continue;
            
            vis[nx][ny] = vis[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); 

    cin >> n >> m >> t;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            vis[i][j] = -1;
        }
    }

    vis[0][0] = 0;
    bfs({0, 0}, 0);
    ans = vis[n-1][m-1];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == sx && j == sy) continue;
            vis[i][j] = -1;
        }
    }
    if (sx != -1) bfs({sx,sy}, 1);
    
    if (ans == -1) ans = vis[n-1][m-1];
    else ans = min(ans, vis[n-1][m-1]);

    if (ans == -1 || ans > t) cout << "Fail";
    else cout << ans;
}   