#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

#define X first 
#define Y second 

int m, n;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dist[105][105];
string board[105];
priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > pq;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int i = 0; i < 105; i++) for (int j = 0; j < 105; j++) dist[i][j] = INF;
    cin >> m >> n;
    for (int i = 0; i < n; i++) cin >> board[i];
    dist[0][0] = 0;
    pq.push({0, {0, 0}});
    
    while (!pq.empty()) {
        int curDist = pq.top().X;
        pair<int, int> curLoc = pq.top().Y;
        pq.pop();
        if (dist[curLoc.X][curLoc.Y] != curDist) continue;
        for (int i = 0; i < 4; i++) {
            int nx = curLoc.X + dx[i];
            int ny = curLoc.Y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (dist[nx][ny] <= dist[curLoc.X][curLoc.Y] + (board[nx][ny]-'0')) continue;
            dist[nx][ny] = dist[curLoc.X][curLoc.Y] + (board[nx][ny]-'0');
            pq.push({dist[nx][ny], {nx, ny}});
        }
    }
    cout << dist[n-1][m-1];
}