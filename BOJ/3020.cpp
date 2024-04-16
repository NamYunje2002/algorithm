#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int ans = 200002, cnt = 0;
    int n, h; cin >> n >> h;
    vector<int> bottom(n/2);
    vector<int> top(n/2);
    for(int i = 0; i < n; i++) {
        if(i%2) cin >> top[i/2];
        else cin >> bottom[i/2];
    }
    sort(bottom.begin(), bottom.end());
    sort(top.begin(), top.end());

    for(int i = 1; i <= h; i++) {
        int lo = 0, hi = n/2;
        while(lo < hi) {
            int mid = (lo+hi)/2;
            if(bottom[mid] >= i) hi = mid;
            else lo = mid+1;
        }
        int bottomCnt = lo;
        
        int p = h - i + 1;
        lo = 0, hi = n/2;
        while(lo < hi) {
            int mid = (lo+hi)/2;
            if(top[mid] < p) lo = mid+1;
            else hi = mid;
        }
        int topCnt = lo;
        
        int totalCnt = n-(bottomCnt+topCnt);
        if(totalCnt < ans) {
            ans = totalCnt;
            cnt = 1;
        }else if(totalCnt == ans) cnt++;
    }
    cout << ans << ' ' << cnt;
}