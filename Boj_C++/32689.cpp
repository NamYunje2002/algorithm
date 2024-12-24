#include <bits/stdc++.h>
using namespace std;

long long ans, cnt;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        cnt += v[i];
    }
    int st = 0, en = n-1, toR = 1;
    while (cnt) {
        int cur = (toR == 1 ? st : en);
        if (v[cur]) {
            v[cur]--;
            cnt--;
            if (cnt == 0) break;
            toR *= -1;
            ans += (st + (n - en));
        } else {
            if (toR == 1) st++;
            else en--;
            ans++;
        }
    }
    cout << ans;
}