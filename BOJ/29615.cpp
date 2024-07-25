#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int ans = 0;
    int n, m; cin >> n >> m;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 0; i < m; i++) {
        int x; cin >> x;
        for(int i = 0; i < n; i++) {
            if(v[i] == x) {
                if(i >= m) ans++;
            }
        }
    }
    cout << ans;
}