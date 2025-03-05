#include <bits/stdc++.h>
using namespace std;

#define S first
#define E second

bool cmp(pair<int, int>& p1, pair<int, int>& p2) {
    if (p1.S == p2.S) return p1.E < p2.E;
    return p1.S < p2.S;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    vector<int> v(366, 0);
    int n; cin >> n;
    while (n--) {
        int s, e; cin >> s >> e;
        for (int i = s; i <= e; i++) {
            v[i]++;
        }
    }
    int x = 0, y = 0, ans = 0;
    for (int i = 1; i <= 365; i++) {
        if (v[i] == 0) {
            ans += x * y;
            x = y = 0;
        } else {
            x = max(x, v[i]);
            y++;
        }
    }
    ans += x * y;
    cout << ans;
}