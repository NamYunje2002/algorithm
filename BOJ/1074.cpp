#include <bits/stdc++.h>
using namespace std;

int n, r, c, ans;
int p10[16];

void solve(int x, int y, int l) {
    
    if(x == r && y == c) {
        cout << ans;
        return;
    }
    if(x <= r && r < x + l && y <= c && c < y + l) {
        solve(x, y, l/2);
        solve(x, y+l/2, l/2);
        solve(x+l/2, y, l/2);
        solve(x+l/2, y+l/2, l/2);
    }else ans+=l*l;
}

int main() {    
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> r >> c;
    p10[0] = 1;
    for(int i = 1; i < 16; i++) p10[i] = p10[i - 1] * 2;
    solve(0,0,p10[n]);
}   