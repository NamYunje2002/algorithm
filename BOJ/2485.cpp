#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if(a%b == 0) return b;
    return gcd(b, a%b);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> v(n-1, 0);
    int pre = -1;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        if(pre == -1) {
            pre = x;
            continue;
        }   
        v[i-1] = x - pre;
        pre = x;
    }
    int ans = 0;
    sort(v.begin(), v.end());
    int m = v[0];
    for(int i = 1; i < n-1; i++) m = gcd(v[i], m);
    for(int i = 0; i < n-1; i++) ans += (v[i] / m - 1);
    cout << ans;
}