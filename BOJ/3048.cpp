#include <bits/stdc++.h>
using namespace std;

int arr[26], vis[30];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    string s, st; cin >> s >> st;
    for(int i = 0; i < (int)s.size(); i++) arr[s[i]-65] = 1;
    for(int i = 0; i < (int)st.size(); i++) arr[st[i]-65] = -1;
    reverse(s.begin(), s.end());
    s += st;
    int t; cin >> t;
    while(t--) {
        for(int i = 0; i < s.size(); i++) {
            int cur = arr[s[i]-65];
            if(i+cur < 0 || i+cur >= s.size()) continue;
            if(cur == arr[s[i+cur]-65]) continue;
            if(vis[i] || vis[i+cur]) continue;
            vis[i] = 1;
            vis[i+cur] = 1;
            char t = s[i];
            s[i] = s[i+cur];
            s[i+cur] = t;
        }
        fill(vis, vis+30, 0);
    }
    cout << s;
}