#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<pair<string, int> > v(n);
    for (int i = 0; i < n; i++) {
        string s; int k; cin >> s >> k;
        v[i] = {s, k};
    }
    for (int i = 0; i < m; i++) {
        int k; cin >> k;
        int lo = -1, hi = n;
        while (lo + 1 < hi) {
            int mid = (lo + hi) / 2;
            if (k <= v[mid].second) hi = mid;
            else lo = mid;
        }
        cout << v[hi].first << "\n";
    }
}