#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    m *= k;
    vector<int> v(n, 0);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end(), greater<>());
    
    int ans = 0;
    for(; ans < n; ans++) {
        m -= v[ans];
        if(m <= 0) break;
    }

    if(m > 0) cout << "STRESS";
    else cout << ans+1;
}