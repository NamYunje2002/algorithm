#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int ans = 0;
    int n, m; cin >> n >> m;
    n = n*2+1; 
    string s; cin >> s;
    for(int i = 0; i < m; i++) {
        if(s[i] == 'O') continue;
        int j = i;
        for(; j+1 < m; j++) if(s[j] == s[j+1]) break;
        if(i < j) {
            int len = j-i+1;
            if(len >= n) {
                ans++;
                len -= n;
                ans += len/2;
            }
        }
        i = j;
    }
    cout << ans;
}