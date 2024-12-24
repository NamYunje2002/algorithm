#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    int ans = -1;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    for(int i = n - 1; i >= 2; i--) {
        if(v[i-1]+v[i-2] > v[i]) ans = max(ans, v[i]+v[i-1]+v[i-2]);
    }
    cout << ans;
}