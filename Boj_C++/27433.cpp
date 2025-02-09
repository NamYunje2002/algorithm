#include <bits/stdc++.h>
using namespace std;

long long f[21];

int main() {
	int n; cin >> n; f[0] = 1; for (int i = 1; i < 21; i++) f[i] = f[i - 1] * i; cout << f[n];
}