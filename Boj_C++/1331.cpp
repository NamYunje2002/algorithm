#include <bits/stdc++.h>
using namespace std;

int board[10][10];
int stX, stY;
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
string ans = "Valid";

bool check(int px, int py, int x, int y) {
    for(int i = 0; i < 8; i++) {
        int nx = px+dx[i];
        int ny = py+dy[i];
        if(nx == x && ny == y) return 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int px = -1, py = -1;
    for(int i = 0; i < 36; i++) {
        string s; cin >> s;
        int x = 6-(s[1] - '0'), y = s[0]-65;
        if(board[x][y] || x < 0 || x > 5 || y < 0 || y > 5) ans = "Invalid";
        board[x][y] = 1;
        if(px == -1 && py == -1) {
            stX = x, stY = y;
            px = x, py = y;
            continue;
        }
        if(!check(px, py, x, y)) ans = "Invalid";
        px = x, py = y;
    }
    if(!check(px, py, stX, stY)) ans = "Invalid";
    cout << ans;
}