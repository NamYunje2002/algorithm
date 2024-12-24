#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

const int INF = 0x3f3f3f3f;

int n, t = 1;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dist[130][130], board[130][130];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    while(t) {
        cin >> n;
        if(!n) break;
        priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > pq;
        for(int i = 0; i < 130; i++) {
            for(int j = 0; j < 130; j++) {
                dist[i][j] = INF;
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> board[i][j];
            }
        }
        dist[0][0] = board[0][0];
        pq.push({dist[0][0], {0, 0}});
        while(!pq.empty()) {
            int d = pq.top().X;
            pair<int, int> cur = pq.top().Y;
            pq.pop();
            if(d != dist[cur.X][cur.Y]) continue;
            for(int i = 0; i < 4; i++) {
                int nx = cur.X + dx[i];
                int ny = cur.Y + dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if(dist[nx][ny] <= dist[cur.X][cur.Y] + board[nx][ny]) continue;
                dist[nx][ny] = dist[cur.X][cur.Y] + board[nx][ny];
                pq.push({dist[nx][ny], {nx, ny}});
            }
        }
        cout << "Problem " << t++ << ": " << dist[n-1][n-1] << "\n";
    }
}