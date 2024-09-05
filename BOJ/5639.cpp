#include <bits/stdc++.h>
using namespace std;

int root, nodeCnt;
int pArr[1000005];
pair<int, int> cArr[1000005];

int findParent(int n, int c) {
    if (pArr[c] > n || pArr[c] == -1) return c;
    return findParent(n, pArr[c]);
}

void dfs(int cur) {
    if (cArr[cur].first) dfs(cArr[cur].first);
    if (cArr[cur].second) dfs(cArr[cur].second);
    cout << cur << "\n";
}

void build(int p) {
    int cur; cin >> cur;
    if (cin.eof()) return;
    nodeCnt++;
    if (p > cur) {
        cArr[p].first = cur;
        pArr[cur] = p;
    } else {
        int parent = findParent(cur, p);
        while (cArr[parent].second) {
            parent = cArr[parent].second;
        }     
        cArr[parent].second = cur;
        pArr[cur] = parent;
    }
    build(cur);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> root;
    pArr[root] = -1;
    if (!cin.eof()) {
        nodeCnt++;
        build(root);
    }
    dfs(root);
}