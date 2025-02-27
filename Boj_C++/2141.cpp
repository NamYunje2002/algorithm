#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define LOC first
#define CNT second

ll sum, ans;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<pair<ll, ll> > v(n);
    for (int i = 0; i < n; i++) {
       cin >> v[i].LOC >> v[i].CNT;
       sum += v[i].CNT;
    }
	sort(v.begin(), v.end());
    
	for (int i = 0; i < n; i++) {
		ans += v[i].CNT;
		if (ans >= (sum + 1) / 2) {
			cout << v[i].LOC;
            break;
		}
	}
}