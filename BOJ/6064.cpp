#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int ans = -1;
        int m, n, x, y; cin >> m >> n >> x >> y;
        if(m == x) x = 0;
        if(n == y) y = 0;
        int l = lcm(m, n);
        for(int i = x; i <= l; i += m) {
            if(i == 0) continue;
            if(i % n == y) {
                ans = i;
                break;
            }
        }
        
        cout << ans << '\n';
    }
}