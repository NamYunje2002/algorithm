#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, mx = -3126, mn = 3126;
int dp[6][6];
string board[6];

void solve(pair<int, int> cur, char op, int ret) {
    if (cur.X >= n || cur.Y >= n) return;
    if (cur.X == n - 1 && cur.Y == n - 1) {
        if (op == '+') ret += board[cur.X][cur.Y] - '0';
        else if (op == '-') ret -= board[cur.X][cur.Y] - '0';
        else if (op == '*') ret *= board[cur.X][cur.Y] - '0';
        mx = max(mx, ret);
        mn = min(mn, ret);
        return;
    }
    if ('0' <= board[cur.X][cur.Y] && board[cur.X][cur.Y] <= '5') {
        if (op != ' ') {
            if (op == '+') ret += board[cur.X][cur.Y] - '0';
            else if (op == '-') ret -= board[cur.X][cur.Y] - '0';
            else if (op == '*') ret *= board[cur.X][cur.Y] - '0';
            op = ' ';
        }
    } else {
        op = board[cur.X][cur.Y];
    }
    solve({cur.X, cur.Y + 1}, op, ret);
    solve({cur.X + 1, cur.Y}, op, ret);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    solve({0, 0}, ' ', board[0][0] - '0');
    cout << mx << " " << mn;    
}