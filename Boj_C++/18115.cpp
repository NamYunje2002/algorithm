#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n;i++) cin >> v[i];
    int num = 1;
    deque<int> dq;
    for(int i = n - 1; i >= 0; i--) {
        if(v[i] == 1) {
            dq.push_front(num);
        }else if(v[i] == 2) {
            dq.insert(dq.begin()+1, num);
        }else if(v[i] == 3) {
            dq.push_back(num);
        }
        num++;
    }
    while(!dq.empty()) {
        cout << dq.front() << ' ';
        dq.pop_front();
    }
}