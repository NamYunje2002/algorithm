#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int vis[55][55];
string board[55];
queue<pair<int, int> > q;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i = 0; i < 55; i++) for(int j = 0; j < 55; j++) vis[i][j] = -1;
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> board[i];
    vis[0][0] = 0;
    q.push({0, 0});
    while(!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        int k = (board[cur.X][cur.Y] == '1' ? 0 : 1);
        for(int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(vis[nx][ny] != -1 && vis[nx][ny] <= vis[cur.X][cur.Y] + k) continue;
            vis[nx][ny] = vis[cur.X][cur.Y] + k;
            q.push({nx, ny});
        }
    }
    cout << vis[n-1][n-1];
}