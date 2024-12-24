#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, a, b; cin >> n >> a >> b;
    if(a > b) swap(a,b);
    int ans = 1;
    while(a || b) {
        if(a%2 && a+1==b) break;
        ans++;
        if(a%2) a = a/2+1;
        else a /= 2;
        if(b%2) b = b/2+1;
        else b /= 2;
    }
    cout << ans;
}