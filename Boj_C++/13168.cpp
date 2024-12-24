#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int sum1, sum2;
int cost1[105][105], cost2[105][105];
map<string, int> cityToNum;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, r; cin >> n >> r;
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        cityToNum[s] = i;   
    }

    int m; cin >> m;
    vector<int> path(m);
    for(int i = 0; i < m; i++) {
        string s; cin >> s;
        path[i] = cityToNum[s];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cost1[i][j] = cost2[i][j] = INF;
        }
    }

    int k; cin >> k;
    for(int i = 0; i < k; i++) {
        int c;
        string t, s, e;
        cin >> t >> s >> e >> c;
        int a = cityToNum[s], b = cityToNum[e];
        c*=2;
        cost1[a][b] = cost1[b][a] = min(cost1[a][b], c);
        cost2[a][b] = cost2[b][a] = min(cost2[a][b], c);
        if(t == "Mugunghwa" || t == "ITX-Saemaeul" || t == "ITX-Cheongchun") cost2[a][b] = cost2[b][a] = 0;
        else if(t == "S-Train" || t == "V-Train") cost2[a][b] = cost2[b][a] /= 2;
    }

    for(int i = 0; i < n; i++) cost1[i][i] = cost2[i][i] = 0;
    
    for(int p = 0; p < n; p++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cost1[i][j] = min(cost1[i][j], cost1[i][p]+cost1[p][j]);
                cost2[i][j] = min(cost2[i][j], cost2[i][p]+cost2[p][j]);
            }
        }
    }

    for(int i = 0; i < m-1; i++) {
        int s = path[i], e = path[i+1];
        sum1 += cost1[s][e];
        sum2 += cost2[s][e];
    }
    sum2 += r*2;
    if(sum1 > sum2) cout << "Yes";
    else cout << "No";
}