/* https://www.acmicpc.net/problem/2022 */

#include <iostream>
#include <cmath>

using namespace std;

double x, y, c, g, h1, h2, low, high, mid;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> x >> y >> c;
	high = min(x, y);
	while (high - low > 0.001) {
		mid = (low + high) / 2;
		h1 = sqrt(pow(x, 2) - pow(mid, 2));
		h2 = sqrt(pow(y, 2) - pow(mid, 2));
		g = (h1 * h2) / (h1 + h2);
		if (g >= c) low = mid;
		else high = mid;
	}
	cout << mid;
}
