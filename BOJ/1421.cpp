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
        int cnt = 0, cost = 0, same = 0;
        for(int j = 0; j < n; j++) {
            if(i != v[j]) {
                if(v[j] % i == 0) cost += (v[j] / i - 1) * c;
                else cost += (v[j] / i) * c;
            }
            else same++;
            cnt += v[j] / i;
        }
        ans = max(ans, max(cnt * i * w - cost, same * i * w));
    }
    cout << ans;
}