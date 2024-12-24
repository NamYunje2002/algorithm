#include <bits/stdc++.h>
using namespace std;

#define CNT first
#define SEQ second

int n, m, k, cur;
vector<pair<int, pair<int, int> > > v(100);

bool cmp(pair<int, pair<int, int> > &p1, pair<int, pair<int, int> > &p2) {
    if(p1.second.CNT == p2.second.CNT) return p1.second.SEQ > p2.second.SEQ;
    return p1.second.CNT > p2.second.CNT;
}

bool cmp2(pair<int, pair<int, int> > &p1, pair<int, pair<int, int> > &p2) {
    return p1.first < p2.first;   
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < 100; i++) v[i].first = i;    
    while(m--) {
        int x; cin >> x; x--;
        if(cur >= n && v[x].second.SEQ == 0) {
            sort(v.begin(), v.end(), cmp);
            v[n-1].second.CNT = 0;
            v[n-1].second.SEQ = 0;    
        }
        sort(v.begin(), v.end(), cmp2);
        v[x].second.CNT++;
        if(v[x].second.SEQ == 0) v[x].second.SEQ = ++cur;
    }
    sort(v.begin(), v.end(), cmp);
    int s = min(n, cur);
    vector<int> ans(s);
    for(int i = 0; i < s; i++) ans[i] = v[i].first+1;
    sort(ans.begin(), ans.end());
    for(int i = 0; i < s; i++) cout << ans[i] << ' ';
}