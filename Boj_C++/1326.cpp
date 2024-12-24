#include <bits/stdc++.h>
using namespace std;

int arr[10001], vis[10001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    fill(vis, vis+10001, -1);
    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    int a, b; cin >> a >> b;
    queue<int> q;
    q.push(a);
    vis[a] = 0;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        int jump = arr[cur];
        while(cur + jump <= n || cur - jump >= 1) {
            if(cur + jump <= n && vis[cur + jump] == -1) {
                vis[cur + jump] = vis[cur] + 1;
                q.push(cur + jump);
            }
            if(cur - jump >= 1 && vis[cur - jump] == -1) {
                vis[cur - jump] = vis[cur] + 1;
                q.push(cur - jump);
            }
            jump += arr[cur];
        }
    }
    cout << vis[b];
}