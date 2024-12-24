#include <bits/stdc++.h>
using namespace std;

int cnt[4];
int vis[4][2][10];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    for (int i = 0; i < 4; i++) cnt[i] = 13;
    string s; cin >> s;
    for (int i = 0; i < (int)s.size(); i+=3) {
        int n = 0;
        if (s[i] == 'K') n = 1;
        else if (s[i] == 'H') n = 2;
        else if (s[i] == 'T') n = 3;
        int m = s[i+1] - '0', k = s[i+2] - '0';
        if (vis[n][m][k]) {
            cout << "GRESKA";
            exit(0);
        }
        vis[n][m][k] = 1;
        cnt[n]--;
    }
    for (int i = 0; i < 4; i++) cout << cnt[i] << ' ';
}