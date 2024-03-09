#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    ll a = 0, b = 1;
    for(int i = 2; i <= n; i++) {
        ll t = b;
        b = a+b;
        a = t;
    }
    cout << (a+2*b)*2;
}