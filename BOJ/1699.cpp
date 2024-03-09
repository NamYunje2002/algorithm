#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    int mn = 0x7f7f7f7f;
    for(int i = sqrt(n); i >= 1; i--) {
        int cnt = 0, t = n, j = i;
        while(t) {
            t -= j*j;
            j = sqrt(t);
            cnt++;
        }
        mn = min(mn, cnt);
    }
    cout << mn;
}

// 미해결