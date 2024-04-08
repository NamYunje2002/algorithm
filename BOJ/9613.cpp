#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if(b) return gcd(b, a%b);
    return a;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int ans = 0, n; cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        sort(v.begin(), v.end());
        for(int i = n-1; i > 0; i--) {
            for(int j = i-1; j >= 0; j--) {
                ans += gcd(v[i], v[j]);
            }
        }
        cout << ans << '\n';
    }
}