#include <bits/stdc++.h>
using namespace std;

int arr[105][2];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    int k; cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> arr[i][0] >> arr[i][1];
        if (arr[i][0] >= 3) arr[i][0]++;
    }
    int a, b; cin >> a >> b;
    if (a >= 3) a++;
    int ans = 0;
    for (int i = 0; i < k; i++) {
        if (a == arr[i][0]) {
            ans += abs(b - arr[i][1]);
        } else if (a + 1 == arr[i][0] || a == arr[i][0] + 1) {
            if (a == 1 || a == 2) {
                ans += min(b + arr[i][1] + m, abs(n - b) + abs(n - arr[i][1]) + m);
            } else {
                ans += min(b + arr[i][1] + n, abs(m - b) + abs(m - arr[i][1]) + n);
            }
        } else {
            if (a == 1) {
                if (arr[i][0] == 4) ans += b + arr[i][1];
                else ans += (n - b) + arr[i][1];
            } else if (a == 2) {
                if (arr[i][0] == 4) ans += b + (m - arr[i][1]);
                else ans += (n - b) + (m - arr[i][1]);
            } else if (a == 4) {
                if (arr[i][0] == 1) ans += b + arr[i][1];
                else ans += (n - b) + arr[i][1];
            } else if (a == 5) {
                if (arr[i][0] == 1) ans += b + (m - arr[i][1]);
                else ans += (n - b) + (m - arr[i][1]);
            }
        }
    }
    cout << ans;
}