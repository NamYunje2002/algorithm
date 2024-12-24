#include <bits/stdc++.h>
using namespace std;

#define LOC first
#define CNT second

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    vector<int> P(n, 0);
    vector<int> T(n, 0);
    for (int i = 0; i < n; i++) cin >> P[i];
    for (int i = 0; i < n; i++) cin >> T[i];
    vector<int> need(n, 0);
    for (int i = 0; i < n; i++) need[i] = T[i] - P[i];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        while (!DQ.empty() && DQ.front().LOC < i) DQ.pop_front();
        int cur = 0;
        if (!DQ.empty()) cur += (DQ.front().LOC - i + 1) * DQ.front().CNT;
        if (cur < need[i]) {
            need[i] -= cur;
            int add = (need[i] / k);
            if (need[i] % k) add++;
            ans += add;
            DQ.push_back({ i+k-1,add });
        }
    }
    cout << ans;
}