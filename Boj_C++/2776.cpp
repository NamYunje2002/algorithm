#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> note(n);
        for(int i = 0; i < n;i++) cin >> note[i];
        sort(note.begin(), note.end());
        int m; cin >> m;
        for(int i = 0; i < m; i++) {
            int x; cin >> x;
            int lo = 0, hi = n, ans = 0;
            while(lo < hi) {
                int mid = (lo+hi)/2;
                if(note[mid] < x) lo = mid+1;
                else if(x < note[mid]) hi = mid;
                else {
                    ans = 1;
                    break;
                }
            }
            cout << ans << '\n';
        }
    }
}