#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int ans = 0;
        int k; cin >> k;
        vector<int> v(20);
        for (int i = 0; i < 20; i++) cin >> v[i];
        for (int i = 0; i < 19; i++) {
            for (int j = i + 1; j < 20; j++) {
                if (v[i] > v[j]) {
                    ans++;
                    int tmp = v[i];
                    v[i] = v[j];
                    v[j] = tmp;
                }
            }
        }
        cout << k << " " << ans << "\n";
    }
}