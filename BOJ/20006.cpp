#include <bits/stdc++.h>
using namespace std;

pair<int, string> board[303][303];

bool cmp(pair<int, string> p1, pair<int, string> p2) {
    return p1.second < p2.second;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int cnt = 0;
    int p, m; cin >> p >> m;
    while(p--) {
        int l; string n; cin >> l >> n;
        for(int i = 0; i < cnt; i++) {
            if(!board[i][m-1].first && board[i][0].first-10 <= l && l <= board[i][0].first+10) {
                for(int j = 0; j < m; j++) {
                    if(board[i][j].first == 0) {
                        board[i][j].first = l;
                        board[i][j].second = n;
                        l = 0;
                        break;
                    }
                }            
            }
        }
        if(l == 0) continue;
        board[cnt][0].first = l;
        board[cnt][0].second = n;
        cnt++;
    }
    for(int i = 0; i < cnt; i++) {
        int pCnt = 0;
        if(board[i][m-1].first) cout << "Started!\n";
        else cout << "Waiting!\n";
        pair<int, string> arr[303];
        for(int j = 0; j < m; j++) {
            if(!board[i][j].first) break;
            pCnt++;
            arr[j] = board[i][j];
        }
        sort(arr, arr+pCnt, cmp);
        for(int j = 0; j < pCnt; j++) cout << arr[j].first << ' ' << arr[j].second << '\n';
    }
}