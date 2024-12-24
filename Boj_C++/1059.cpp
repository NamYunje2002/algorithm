#include <bits/stdc++.h>
using namespace std;

int l, n, ans;
int s[52];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> l;
    for(int i = 0; i < l; i++) cin >> s[i];
    cin >> n;
    int a = 1, b = 1000, c = 0;
    for(int i = 0; i < l; i++) {
        if(s[i] < n && s[i] > a) a = s[i];
        if(s[i] > n && s[i] < b) b = s[i];
        if(s[i] == n) c = 1;
    }
    if(!c) {
        a++;
        b--;
        cout << a << ' ' << b << '\n';
        ans = ((n-1) - a + 1) * (b - n + 1);
        ans += (b - n);
    }
    cout << ans;
}