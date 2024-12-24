#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int idx = 1;
        int up = 0, down = 0, le = 0, ri = 0;
        int x = 0, y = 0;
        string s; cin >> s;
        for(int i = 0; i < (int)s.size(); i++) {
            if(s[i] == 'F') x += dx[idx], y += dy[idx];
            if(s[i] == 'B') x += dx[(idx+2)%4], y += dy[(idx+2)%4];
            if(s[i] == 'L') idx = (idx+1)%4;
            if(s[i] == 'R') idx = (idx+3)%4;
            up = min(up, x);
            down = max(down, x);
            le = min(le, y);
            ri = max(ri, y);
        }
        cout << (down - up) * (ri - le) << '\n';
    }
}