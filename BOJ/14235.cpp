#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    priority_queue<int> pq;
    int n; cin >> n;
    while(n--) {
        int a; cin >> a;
        if(a) {
            while(a--) {
                int x; cin >> x;
                pq.push(x);
            }
        }else{
            if(pq.empty()) cout << -1;
            else {
                cout << pq.top();
                pq.pop();
            }
            cout << '\n';
        }
    }
}