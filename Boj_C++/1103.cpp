#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int curDist[55][55], finished[55][55];
string board[55];

bool isValid(int x, int y) {
    return !(x < 0 || x >= n || y < 0 || y >= m);
}

void dfs(int x, int y) {
    int dist = board[x][y] - '0';
    for(int i = 0; i < 4; i++) {
        int nx = x + dist * dx[i];
        int ny = y + dist * dy[i];
        if(!isValid(nx, ny) || board[nx][ny] == 'H') {
            if(ans != -1) ans = max(ans, curDist[x][y]);
            continue;
        }
        if(curDist[nx][ny]) {
            ans = -1;
            return;
        }
        if(finished[nx][ny] != 0 && finished[nx][ny] >= curDist[x][y] + 1) continue;
        finished[nx][ny] = curDist[nx][ny] = curDist[x][y] + 1;
        dfs(nx,ny);
        curDist[nx][ny] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> board[i];
    finished[0][0] = curDist[0][0] = 1;
    dfs(0, 0);
    cout << ans << '\n';

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << finished[i][j] << " ";
        }
        cout << "\n";
    }
}