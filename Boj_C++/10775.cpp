#include <bits/stdc++.h>
using namespace std;

int Find(int x, vector<int> &v) {
    if(x == v[x]) return x;
    return Find(v[x], v);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int g, p, ans = 0; cin >> g >> p;   
    vector<int> v(g+1);
    for(int i = 0; i <= g; i++) v[i] = i;
    while(p--) {
        int x; cin >> x;
        int y = Find(x, v);
        if(y < 1) break;
        v[x] = (y-1);
        ans++;
        for(int i = 1; i <= g; i++) cout << v[i] << ' ';
        cout << '\n';
    }
    cout << ans;
}