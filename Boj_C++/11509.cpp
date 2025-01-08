#include <bits/stdc++.h>
using namespace std;

int n, ans;
int vis[1000001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    while (n--) {
        int h; cin >> h;
        vis[h]++;
        if (vis[h + 1]) {
            vis[h + 1]--;
        } else {
            ans++;
        }
    }
    cout << ans;
}