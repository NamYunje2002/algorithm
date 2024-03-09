#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        map<string, pair<int, int> > mp;
        int arr[1001];
        fill(arr, arr+1001, 0);
        
        int n; cin >> n;
        for(int i = 0; i < n; i++) {
            string s; cin >> s;
            mp[s].X = i;
        }
        for(int i = 0; i < n; i++) {
            string s; cin >> s;
            mp[s].Y = i;
        }
        for(auto iter = mp.begin(); iter != mp.end(); iter++) {
            arr[iter->second.X] = iter->second.Y;
        }

        string *p = new string[n];
        for(int i = 0; i < n; i++) cin >> p[i];
        for(int i = 0; i < n; i++) cout << p[arr[i]] << " \n"[i == n-1];
        delete[] p;
    }
}