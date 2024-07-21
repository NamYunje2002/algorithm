#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, c, w, ans;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> c >> w;
    vector<ll> v(n); 
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    for(int i = 1; i <= v[n-1]; i++) {
        ll cnt = 0, cut = 0, sum = 0;
        for(int j = 0; j < n; j++) {
            cnt = v[j] / i;
            cut = (v[j] % i == 0) ? v[j]/i-1 : v[j]/i; 
            ll cost = i*w*cnt - c*cut;
            if(cost > 0) sum += cost;
        }   
        ans = max(ans, sum);
    }
    cout << ans;
}