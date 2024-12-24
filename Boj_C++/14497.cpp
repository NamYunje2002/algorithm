#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int main() {
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    int n, m; cin >> n >> m;
    pair<int, int> J, C;
    cin >> J.X >> J.Y >> C.X >> C.Y;
    J.X--; J.Y--; C.X--; C.Y--;
    vector<string> board(n);
    vector<vector<int> > cnt(n, vector<int> (m, 0));
    for (int i = 0; i < n; i++) { cin >> board[i]; }
    deque<pair<int, int> > DQ;
    DQ.push_front({J.X, J.Y});
    cnt[J.X][J.Y] = 1;
    while (!DQ.empty()) {
        pair<int, int> cur = DQ.front(); DQ.pop_front();
        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) { continue; }
            int isFriend = (board[nx][ny] == '1');
            if (cnt[nx][ny] != 0 && cnt[nx][ny] <= cnt[cur.X][cur.Y] + isFriend) { continue; }
            cnt[nx][ny] = cnt[cur.X][cur.Y] + isFriend;
            if (!isFriend) { DQ.push_front({nx, ny}); }
            else { DQ.push_back({nx, ny}); }
        }   
    }
    cout << cnt[C.X][C.Y];
}