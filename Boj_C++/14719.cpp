#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int ans = 0;
    int h, w; cin >> h >> w;
    vector<int> v(w);
    for(int i = 0; i < w; i++) cin >> v[i];
    int stIdx = 0, mxIdx = -1;
    for(int i = 0; i < w; i++) {
        if(v[stIdx] == 0) {     
            stIdx = i;
            continue;
        }
        if(v[i] >= v[stIdx]) {
            for(int j = stIdx + 1; j < i; j++) ans += (v[stIdx] - v[j]);
            stIdx = i;
            mxIdx = -1;
        } else {
            if(mxIdx == -1 || v[i] > v[mxIdx]) {
                mxIdx = i;
            }
            if(i == w-1) {
                for(int j = stIdx + 1; j < mxIdx; j++) ans += (v[mxIdx] - v[j]);
                if(mxIdx == w - 1) break;
                i = mxIdx;
                stIdx = i;
                mxIdx = -1;
            }
        }
    }
    cout << ans;
}