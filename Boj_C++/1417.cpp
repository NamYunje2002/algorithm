#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, ans; 
    vector<int> v (n, 0);
    priority_queue<int> pq;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        if(i) pq.push(v[i]);
    }
    while(1) {
        int mx = pq.top(); pq.pop();
        if(mx < v[0]) break;
        cout << mx << "\n";
        v[0]++;
        ans++;
        pq.push(mx-1);
    }
    cout << ans;
}