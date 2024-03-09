#include <bits/stdc++.h>
using namespace std;

int n, m; 
int arr[9], ans[9], vis[9];
set<string> st;

void solve(int k, int cnt) {
    if(cnt == m) {
        string s = "";
        for(int i = 0; i < cnt; i++) {
            s += to_string(ans[i]) + " ";
        }
        if(st.find(s) == st.end()) {
            for(int i = 0; i < cnt; i++) cout << ans[i] << ' ';
            cout << '\n';
            st.insert(s);
        }
        return;
    }
    for(int i = 0; i < n; i++) {
        if(vis[i]) continue;
        ans[k] = arr[i];
        vis[i] = 1;
        solve(k+1, cnt+1);
        vis[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n;i++) cin >> arr[i];
    sort(arr, arr+n);
    solve(0, 0);
}