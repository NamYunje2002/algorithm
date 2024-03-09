#include <bits/stdc++.h>
using namespace std;

int n, m;
int deg[1002];
vector<int> adj[1002], ans[1002];
string numToName[1002];
map<string, int> nameToNum;
queue<int> q;
priority_queue<string, vector<string>, greater<string> > pq;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        nameToNum[s] = i;
        numToName[i] = s;
    }
    cin >> m;
    for(int i = 0; i < m; i++) {
        string x, y; cin >> x >> y;
        adj[nameToNum[y]].push_back(nameToNum[x]);
        deg[nameToNum[x]]++;
    }
    for(int i = 0; i < n; i++) {
        if(!deg[i]) {
            q.push(i);
            pq.push(numToName[i]);
        }
    }
    cout << pq.size() << '\n';
    while(!pq.empty()) {
        cout << pq.top() << ' ';
        pq.pop();
    }
    cout << '\n';
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(int i = 0; i < (int)adj[cur].size(); i++) {
            int nxt = adj[cur][i];
            deg[nxt]--;
            if(deg[nxt] == 0) {
                ans[cur].push_back(nxt);
                q.push(nxt);
            }
        }
    }
    for(auto iter = nameToNum.begin(); iter != nameToNum.end(); iter++) {
        string name = iter -> first;
        int num = nameToNum[iter->first];
        cout << name << ' ' << (int)ans[num].size();
        for(int i = 0; i < (int)ans[num].size(); i++) {
            int nxt = ans[num][i];
            pq.push(numToName[nxt]);
        }
        while(!pq.empty()) {
            cout << ' ' << pq.top();
            pq.pop();
        }
        cout << '\n';
    }
}