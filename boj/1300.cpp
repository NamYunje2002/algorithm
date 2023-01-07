// https://www.acmicpc.net/problem/1300 

#include <iostream>

using namespace std;

int n, k, cnt, low, high, mid;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	high = k;
	while (low < high) {
		cnt = 0;
		mid = (low + high) / 2;
		for (int i = 1; i <= n; i++) cnt += min(mid / i, n);
		if (k <= cnt) high = mid;
		else low = mid + 1;
	}
	cout << low;
}
