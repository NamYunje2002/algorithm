/* https://www.acmicpc.net/problem/14003 */

#include <iostream>
#include <stack>

using namespace std;

int n, idx, length, mid, arr[1000000], lis[1000000], ans[1000000];
stack<int> S;

int BS(int low, int high, int target) {
	while (low < high) {
		mid = (low + high) / 2;
		if (lis[mid] < target) low = mid + 1;
		else high = mid;
	}
	return high;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	
	lis[0] = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] > lis[length]) {
			lis[++length] = arr[i];
			ans[i] = length;
		}
		else {
			idx = BS(0, length, arr[i]);
			ans[i] = idx;
			lis[idx] = arr[i];
		}
	}
	cout << length + 1 << "\n";
  
	for (int i = n - 1; i > -1; i--) {
		if (ans[i] == length) {
			S.push(arr[i]);
			length--;
		}
	}
	while (!S.empty()) {
		cout << S.top() << " ";
		S.pop();
	}
}
