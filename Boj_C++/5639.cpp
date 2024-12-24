#include <bits/stdc++.h>
using namespace std;

int nodeCnt = -1;
int arr[10005];

void solve(int st, int en) {
    if (st >= en) return;
    int idx = st;
    while (idx < en) {
        if (arr[++idx] > arr[st]) break;
    } 
    solve(st+1, idx);
    solve(idx, en);
    cout << arr[st] << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    while(cin >> arr[++nodeCnt]);
    solve(0, nodeCnt);
}