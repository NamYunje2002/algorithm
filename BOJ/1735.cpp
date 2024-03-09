#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y) {
    if(x % y == 0) return y;
    else return gcd(y, x % y);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int a, b, c, d; cin >> a >> b >> c >> d;
    int n, m;
    n = b*d;
    m = a*d+b*c;
    int k = gcd(max(n, m), min(n, m));
    cout << m / k << ' ' << n / k;
}