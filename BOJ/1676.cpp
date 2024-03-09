#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n; cin >> n;
    int ans = 0;
    for(int i = 5; i <= n; i*=5) ans += n/i;
    cout << ans;    
}