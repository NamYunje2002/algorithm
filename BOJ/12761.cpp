#include <bits/stdc++.h>
using namespace std;

int vis[100002];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int a, b, n, m; 
    cin >> a >> b >> n >> m;
    vis[n] = 1;
    queue<int> q;
    q.push(n);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        if(cur+1 <= 100000 && !vis[cur+1]) {
            vis[cur+1] = vis[cur]+1;
            q.push(cur+1);
        }
        if( cur-1 >= 0 && !vis[cur-1]) {
            vis[cur-1] = vis[cur]+1;
            q.push(cur-1);
        }
        if(cur+a <= 100000 && !vis[cur+a]) {
            vis[cur+a] = vis[cur]+1;
            q.push(cur+a);
        }
        if(cur-a >= 0 && !vis[cur-a]) {
            vis[cur-a] = vis[cur]+1;
            q.push(cur-a);
        }
        if(cur+b <= 100000 && !vis[cur+b]) {
            vis[cur+b] = vis[cur]+1;
            q.push(cur+b);
        }
        if(cur-b >= 0 && !vis[cur-b]) {
            vis[cur-b] = vis[cur]+1;
            q.push(cur-b);
        }
        if(cur*a <= 100000 && !vis[cur*a]) {
            vis[cur*a] = vis[cur]+1;
            q.push(cur*a);
        }
        if(cur*b <= 100000 && !vis[cur*b]) {
            vis[cur*b] = vis[cur]+1;
            q.push(cur*b);
        }
        if(vis[m]) break;
    }
    cout << vis[m] - 1;
}