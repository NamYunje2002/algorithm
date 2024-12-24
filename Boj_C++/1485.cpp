#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    pair<int,int> coor[4];
    int t; cin >> t;
    while(t--) {
        for(int i = 0; i < 4; i++) cin >> coor[i].X >> coor[i].Y;
        int dist = -1, chk = 1;
        vector<int> vv;
        for(int i = 0; i < 4; i++) {
            vector<int> v;
            for(int j = 0; j < 4; j++) {
                if(i != j) {
                    int x = coor[i].X-coor[j].X, y = coor[i].Y-coor[j].Y;
                    v.push_back(x*x+y*y);
                }
            }
            int cnt[3] = {0,0,0};
            if(v[0] == v[1]) {
                cnt[0]++;
                cnt[1]++;
            }
            if(v[1] == v[2]) {
                cnt[1]++;
                cnt[2]++;
            }
            if(v[2] == v[0]) {
                cnt[2]++;
                cnt[0]++;
            }
            int mxCnt = -1, d = 0;
            for(int i = 0; i < 3; i++) {
                if(cnt[i] > mxCnt) {
                    mxCnt = cnt[i];
                    d = v[i];
                }
            }
            if(mxCnt == 1) {
                if(dist == -1) dist = d;
                else if(dist != d) chk = 0;
            }else chk = 0;
            if(chk) {
                if(v[0] == v[1]) vv.push_back(v[2]);
                if(v[1] == v[2]) vv.push_back(v[0]);
                if(v[2] == v[0]) vv.push_back(v[1]);
            }
        }
        sort(vv.begin(), vv.end());
        if((int)vv.size() < 4 || vv[0] != vv[3]) chk = 0;
        if(chk) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
}