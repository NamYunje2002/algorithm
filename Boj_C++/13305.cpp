#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ans, totalDist;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    vector<int> dist_v(n-1);
    vector<int> oil_v(n);
    for(int i = 0; i < n - 1; i++) {
        cin >> dist_v[i];
        totalDist += dist_v[i];
    }
    for(int i = 0; i < n; i++) cin >> oil_v[i];
    
    for(int i = 0; i < n; i++) {
        ll a = totalDist / oil_v[i];
    }
}