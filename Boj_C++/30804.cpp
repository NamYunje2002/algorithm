#include <bits/stdc++.h>
using namespace std;

int n, ans;
int cnts[10], arr[200005];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    int lo = 0, hi = 0, d = 0;
    while(hi < n) {
        if(!cnts[arr[hi]]) d++;
        cnts[arr[hi]]++;
        while(d > 2) {
            cnts[arr[lo]]--;
            if(!cnts[arr[lo]]) d--;
            lo++;
        }
        ans = max(ans, hi-lo+1);
        hi++;
    }
    cout << ans;
}
