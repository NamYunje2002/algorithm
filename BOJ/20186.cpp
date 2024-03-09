#include <bits/stdc++.h>
using namespace std;

int cnt, ans;
priority_queue<int> pq;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        pq.push(x);
    }
    for(int i = 0; i < k; i++) cnt += i;
    while(k--) {
        ans += pq.top();
        pq.pop();
    }
    cout << ans - cnt;
}