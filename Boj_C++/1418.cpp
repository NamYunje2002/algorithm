#include <bits/stdc++.h>
using namespace std;

int ans;
int pNum[100001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i = 0; i < 100001; i++) pNum[i] = 1;
    pNum[0] = 0, pNum[1] = 0;
    for(int i = 2; i*i < 100001; i++) if(pNum[i]) for(int j = i*i; j < 100001; j += i) pNum[j] = 0; 
    int n, k; cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        int t = i, x = 2;
        while(t != 1 && x <= k) {
            if(!pNum[x]) {
                x++;
                continue;
            }
            if(t % x == 0) t /= x;
            else x++;
        }
        if(t == 1) ans++;
    }
    cout << ans;
}