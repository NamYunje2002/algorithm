#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int vis[252][252], board[252][252];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int m, n; cin >> m >> n;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j] && !vis[i][j]) {
                ans++;
                queue<pair<int, int> > q;
                q.push({i, j});
                vis[i][j] = 1;
                while(!q.empty()) {
                    pair<int, int> cur = q.front(); q.pop();
                    for(int k = 0; k < 8; k++) {
                        int nx = cur.X+dx[k];
                        int ny = cur.Y+dy[k];
                        if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                        if(vis[nx][ny] || !board[nx][ny]) continue;
                        vis[nx][ny] = 1;
                        q.push({nx,ny});
                    }
                }
            }
        }
    }
    cout << ans;
}