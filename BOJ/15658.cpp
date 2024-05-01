#include <bits/stdc++.h>
using namespace std;

int n, mx = -2e9-1, mn = 2e9+1;
int num[15], op[50], opCnt[5];

void setOp(int cnt) {
    if(cnt == n) {
        int rsl = num[0];
        for(int i = 1; i < n; i++) {
            if(op[i] == 0) rsl += num[i];
            if(op[i] == 1) rsl -= num[i];
            if(op[i] == 2) rsl *= num[i];
            if(op[i] == 3) rsl /= num[i];
        }
        mx = max(mx, rsl);
        mn = min(mn, rsl);
        return;
    }
    for(int i = 0; i < 4; i++) {
        if(opCnt[i] != 0) {
            opCnt[i]--;
            op[cnt] = i;
            setOp(cnt+1);
            opCnt[i]++;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> num[i];
    for(int i = 0; i < 4; i++) cin >> opCnt[i];
    setOp(1);
    cout << mx << '\n' << mn;
}