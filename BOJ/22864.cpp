#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int a, b, c, m; cin >> a >> b >> c >> m;
    int p = 0, ans = 0;
    for(int i = 0; i < 24; i++) {
        if(p+a>m) {
            p = max(p-c, 0);
        }else{
            p += a;
            ans += b;
        }
    }
    cout << ans;
}