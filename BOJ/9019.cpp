#include <bits/stdc++.h>
using namespace std;

int vis[10000];
char comArr[4] = {'D', 'S', 'L', 'R'};
queue<pair<int, string> > q;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int a, b; cin >> a >> b;
        string ans = "";
        q.push({a, ""});
        vis[a] = 1;
        while(!q.empty()) {
            int cur = q.front().first;
            string com = q.front().second; 
            q.pop();
            if(cur == b) {
                ans = com;
                break;
            }
            for(int i = 0; i < 4; i++) {
                int nxt = 0;
                if(i==0) {
                    nxt = 2*cur%10000;
                }else if(i==1) {
                    nxt = (cur==0?9999:cur-1);
                }else if(i==2) {
                    string tmpNxt = to_string(cur);
                    tmpNxt.insert(0, 4-(int)tmpNxt.size(), '0');
                    char tmp = tmpNxt[0];
                    for(int j = 0; j < (int)tmpNxt.size()-1; j++) {
                        tmpNxt[j] = tmpNxt[j+1];
                    }
                    tmpNxt[(int)tmpNxt.size()-1] = tmp;
                    nxt = stoi(tmpNxt);
                }else if(i==3) {
                    string tmpNxt = to_string(cur);
                    tmpNxt.insert(0, 4-(int)tmpNxt.size(), '0');
                    char tmp = tmpNxt[(int)tmpNxt.size()-1];
                    for(int j = (int)tmpNxt.size()-1; j > 0; j--) {
                        tmpNxt[j] = tmpNxt[j-1];
                    }
                    tmpNxt[0] = tmp;
                    nxt = stoi(tmpNxt);
                }
                if(vis[nxt]) continue;
                if(nxt == b) {
                    while(!q.empty()) q.pop();
                    ans = com+comArr[i];
                    break;
                }
                vis[nxt] = 1;
                q.push({nxt, com+comArr[i]});
            }
        }
        cout << ans << "\n";
        while(!q.empty()) q.pop();
        fill(vis, vis+10000, 0);
    }
}