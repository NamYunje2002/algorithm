#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int ans = 0;
    int n, m; cin >> n >> m;
    n = n*2+1;
    string s; cin >> s;
    for(int i = 0; i <= m-n; i++) {
        int chk = 0;
        for(int j = 0; j < n; j++) if(j%2==0&&s[i+j]=='O'||j%2==1&&s[i+j]=='I') chk=1;
        if(!chk) {
            ans++;
        }
    }
    cout << ans;
}