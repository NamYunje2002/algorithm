#include <bits/stdc++.h>
using namespace std;

#define HEIGHT first
#define COUNT second
typedef long long ll;
ll ans;
stack<pair<int, int> > ST;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    while (n--) {
        int curHeight; cin >> curHeight;
        int cnt = 1;
        while (!ST.empty() && ST.top().HEIGHT <= curHeight) {
            ans += ST.top().COUNT;
            if (ST.top().HEIGHT == curHeight) { cnt += ST.top().COUNT; }
            ST.pop();
        }
        if (!ST.empty()) { ans++; }
        ST.push({curHeight, cnt});
    }
    cout << ans;
}