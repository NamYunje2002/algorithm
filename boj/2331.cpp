// https://www.acmicpc.net/problem/2331

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int a, p, ans;
vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> a >> p;
	v.push_back(a);
	while(1) {
		int tmp = v.back(), a = 0;
		while (tmp) {
			a += pow(tmp % 10, p);
			tmp /= 10;
		}
		if ((find(v.begin(), v.end(), a)) != v.end()) {
			ans = find(v.begin(), v.end(), a) - v.begin();
            break;
        }
		v.push_back(a);
	}
	cout << ans;
}
