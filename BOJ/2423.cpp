#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m; 
int slash_dx[6] = {-1, -1, 0, 1, 1, 0}, slash_dy[6] = {0, 1, 1, 0, -1, -1};
int backslash_dx[6] = {0, 1, 1, 0, -1, -1}, backslash_dy[6] = {1, 1, 0, -1, -1, 0};
int dist[505][505];
string board[505];
queue<pair<char, pair<int, int> > > dq;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) dist[i][j] = -1;
    for (int i = 0; i < n; i++) cin >> board[i];
    dist[0][0] = 0;
    if (board[0][0] == '/') {
        board[0][0] = '\\';
        dist[0][0]++;
    } 
    if (board[n-1][m-1] == '/') {
        board[n-1][m-1] = '\\';
        dist[0][0]++;
    }
    dq.push({ '\\', { 0, 0 }});
    while (!dq.empty()) {
        char cur = dq.front().X;
        pair<int, int> curLoc = dq.front().Y; 
        dq.pop();
        for (int i = 0; i < 6; i++) {
            int nx = curLoc.X;
            int ny = curLoc.Y;
            if (cur == '/') {
                nx += slash_dx[i];
                ny += slash_dy[i];
            } else {
                nx += backslash_dx[i];
                ny += backslash_dy[i];
            }
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            int isChange = 0;
            if ((i == 1 || i == 4) && board[nx][ny] != cur) isChange = 1;
            if ((i != 1 && i != 4) && board[nx][ny] == cur) isChange = 1;
            if (dist[nx][ny] != -1 && dist[nx][ny] <= dist[curLoc.X][curLoc.Y] + isChange) continue;
            if ((nx == n-1 && ny == m-1) && isChange) continue; 
            dist[nx][ny] = dist[curLoc.X][curLoc.Y] + isChange;
            if (isChange) {
                if (board[nx][ny] == '/') dq.push({ '\\', { nx,ny }});
                else dq.push({ '/', { nx,ny }});
            } else {
                dq.push({ board[nx][ny], { nx,ny }});
            } 
        }
    }
    if (dist[n-1][m-1] == -1) cout << "NO SOLUTION";
    else cout << dist[n-1][m-1];
}