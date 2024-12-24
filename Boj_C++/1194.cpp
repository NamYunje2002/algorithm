#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int ans = 0x7f7f7f7f;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int vis[52][52][64];
string board[52];
queue<pair<pair<int, int>, int> > q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> board[i];
        for(int j = 0; j < m; j++) {
            if(board[i][j] == '0') {
                q.push({{i, j}, 0});
                vis[i][j][0] = 1;
            }
        }
    }
    while(!q.empty()) {
        pair<int, int> curLoc = q.front().first;
        int curKey = q.front().second;
        q.pop();
        if(board[curLoc.X][curLoc.Y] == '1') ans = min(ans, vis[curLoc.X][curLoc.Y][curKey] - 1);
        
        for(int i = 0; i < 4; i++) {
            int nx = curLoc.X + dx[i];
            int ny = curLoc.Y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] == '#') continue;
            if('a' <= board[nx][ny] && board[nx][ny] <= 'f') {
                int nxtKey = curKey | (1<<board[nx][ny]-'a');
                if(!vis[nx][ny][nxtKey]) {
                    q.push({{nx, ny}, nxtKey});
                    vis[nx][ny][nxtKey] = vis[curLoc.X][curLoc.Y][curKey] + 1;
                }
            } 
            if('A' <= board[nx][ny] && board[nx][ny] <= 'F') {
                if(!(curKey & (1<<(int)(board[nx][ny]-'A')))) {
                    continue;
                }
            }
            if(vis[nx][ny][curKey]) continue;
            vis[nx][ny][curKey] = vis[curLoc.X][curLoc.Y][curKey] + 1;
            q.push({{nx, ny}, curKey});
        }
    }
    if(ans == 0x7f7f7f7f) ans = -1;
    cout << ans;
}