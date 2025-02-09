#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> A(n), B(n);
	for (int i = 0; i < n; i++) cin >> A[i];
	for (int i = 0; i < n; i++) cin >> B[i];

	int m; cin >> m;
	vector<int> C(m);
	for (int i = 0; i < m; i++) cin >> C[i];

	int cnt = 0;
	for (int i = n - 1; i >= 0 && cnt < m; i--) {
		if (!A[i]) {
			cout << B[i] << ' ';
			cnt++;
		}
	}
	for (int i = 0; i < m && cnt < m; i++, cnt++) cout << C[i] << ' ';
}