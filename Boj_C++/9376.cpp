#include <bits/stdc++.h>
using namespace std;

#define X first 
#define Y second

int t, h, w, ans;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

void solve(vector<string> board, vector<vector<int> > &cnt, pair<int, int> start) {
    if ((cnt[start.X][start.Y] != -1 && cnt[start.X][start.Y] <= (board[start.X][start.Y] == '#')) || board[start.X][start.Y] == '*') { return; }
    deque<pair<int, int> > DQ;
    cnt[start.X][start.Y] = 0;
    if (board[start.X][start.Y] == '#') { cnt[start.X][start.Y]++; }
    DQ.push_front({ start.X, start.Y });
    while (!DQ.empty()) {
        pair<int, int> cur = DQ.front(); DQ.pop_front();
        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) { continue; } 
            if (board[nx][ny] == '*') { continue; }
            int isOpen = (board[nx][ny] == '#' ? 1 : 0);
            if (cnt[nx][ny] != -1 && (cnt[nx][ny] <= cnt[cur.X][cur.Y] + isOpen)) { continue; }
            cnt[nx][ny] = cnt[cur.X][cur.Y] + isOpen;
            if (!isOpen) { DQ.push_front({ nx, ny }); } 
            else { DQ.push_back({ nx, ny }); }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    cin >> t;
    while (t--) {
        cin >> h >> w;
        pair<int, int> convict1{-1, -1};
        pair<int, int> convict2{-1, -1};
        vector<string> board(h);
        vector<vector<int> > escapeCnt(h, vector<int> (w, -1));
        vector<vector<int> > convict1Cnt(h, vector<int> (w, -1));
        vector<vector<int> > convict2Cnt(h, vector<int> (w, -1));
        for (int i = 0; i < h; i++) {
            cin >> board[i];
            for (int j = 0; j < w; j++) {
                if (board[i][j] == '$') {
                    if (convict1.X == -1) { convict1 = {i, j}; }
                    else { convict2 = {i, j}; }
                }
            }
        }
        for (int i = 0; i < h; i += (h-1)) {
            for (int j = 0; j < w; j++) {
                solve(board, escapeCnt, {i,j});
            }
        }
        for (int i = 0; i < w; i += (w-1)) {
            for (int j = 0; j < h; j++) {
                solve(board, escapeCnt, {j,i});
            }
        }
        solve(board, convict1Cnt, {convict1.X,convict1.Y});
        solve(board, convict2Cnt, {convict2.X,convict2.Y});
        int minCnt1 = 10005, minCnt2 = 10005;
        for (int i = 0; i < h; i += (h-1)) {
            for (int j = 0; j < w; j++) {
                if (convict1Cnt[i][j] != -1) { minCnt1 = min(minCnt1, convict1Cnt[i][j]); }
                if (convict2Cnt[i][j] != -1) { minCnt2 = min(minCnt2, convict2Cnt[i][j]); }
            }
        } 
        for (int i = 0; i < w; i += (w-1)) {
            for (int j = 0; j < h; j++) {
                if (convict1Cnt[j][i] != -1) { minCnt1 = min(minCnt1, convict1Cnt[j][i]); }
                if (convict2Cnt[j][i] != -1) { minCnt2 = min(minCnt2, convict2Cnt[j][i]); }
            }
        }
        ans = minCnt1+minCnt2;
        for (int i = 0; i < h; i++) {
            for (int j = 0 ; j < w; j++) {
                if (escapeCnt[i][j] == -1 || convict1Cnt[i][j] == -1 || convict2Cnt[i][j] == -1) { continue; }
                int totalCnt = escapeCnt[i][j] + convict1Cnt[i][j] + convict2Cnt[i][j];
                if (board[i][j] == '#') { totalCnt-=2; }
                ans = min(ans, totalCnt);
            }
        }
        cout << ans << '\n';
    }
}