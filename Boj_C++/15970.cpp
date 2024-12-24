#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, ans; 
pair<int, int> arr[5001];

bool cmp(pair<int, int> &p1, pair<int, int> &p2) {
    if(p1.Y == p2.Y) return p1.X < p2.X;
    return p1.Y < p2.Y;
}

int main()  {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i].X >> arr[i].Y;
    }
    sort(arr, arr+n, cmp);
    ans = abs(arr[0].X-arr[1].X) + abs(arr[n-1].X-arr[n-2].X);
    for(int i = 1; i < n-1; i++) {
        int l = 100001, r = 100001;
        if(arr[i-1].Y == arr[i].Y) l = abs(arr[i-1].X-arr[i].X);
        if(arr[i+1].Y == arr[i].Y) r = abs(arr[i+1].X-arr[i].X);
        ans += min(l, r);
    }
    cout << ans;
}