#include <bits/stdc++.h>
using namespace std;

int p, r;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<int> v(m);
    for(int i = 0; i < m; i++) cin >> v[i];
    sort(v.begin(), v.end(), greater<>());
    for(int i = 0; i < m; i++) {
        int s = v[i]*(min(i+1, n));
        if(s > r) {
            p = v[i];
            r = s;
        }
    }    
    cout << p << ' ' << r;
}