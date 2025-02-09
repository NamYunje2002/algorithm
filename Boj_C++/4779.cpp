#include <bits/stdc++.h>
using namespace std;

int arr[13];

void Solve(int n) {
	if (n == 1) {
		cout << '-';
		return;
	}
	Solve(n / 3);
	for (int i = 0; i < n / 3; i++) cout << ' ';
	Solve(n / 3);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	arr[0] = 1;
	for (int i = 1; i < 13; i++) arr[i] = arr[i - 1] * 3;
	int n;
	while (cin >> n) {
		Solve(arr[n]);
		cout << "\n";
	}
}