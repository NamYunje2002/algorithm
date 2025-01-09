#include <bits/stdc++.h>
using namespace std;

int ans;
int arr[35][35];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            for (int k = j + 1; k < m; k++) {
                int rsl = 0;
                for (int l = 0; l < n; l++) {
                    int mx = 0;
                    for (int p = 0; p < m; p++) {
                        if (p == i || p == j || p == k) {
                            mx = max(mx, arr[l][p]);
                        }
                    }
                    rsl += mx;
                }
                ans = max(ans, rsl);
            }
        }
    }
    cout << ans;
}