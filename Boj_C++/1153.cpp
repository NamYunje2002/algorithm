#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> pVec(n + 1, 1);
	pVec[1] = 0;
	for (int i = 2; i * i <= n; i++) if (pVec[i]) for (int j = i * i; j <= n; j += i) pVec[j] = 0;
	if (n < 8) cout << -1;
	else if (n % 2 != 0) {
		n -= 5;
		cout << "2 3 ";
		for (int i = 2; i <= n / 2; i++) {
			if (pVec[i] && pVec[n - i]) {
				cout << i << " " << n - i;
				break;
			}
		}
	}
	else {
		n -= 4;
		cout << "2 2 ";
		for (int i = 2; i <= n / 2; i++) {
			if (pVec[i] && pVec[n - i]) {
				cout << i << " " << n - i;
				break;
			}
		}
	}
}