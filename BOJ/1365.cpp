/* https://www.acmicpc.net/problem/1365 */


// STL Lower Bound 사용
#include <iostream>

using namespace std;

int n, length, mid, arr[100000], lis[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
  
	lis[0] = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] > lis[length]) lis[++length] = arr[i];
		else lis[lower_bound(lis, lis + length, arr[i]) - lis] = arr[i];
	}
	cout << n - length - 1;
}



// STL Lower Bound 미사용
#include <iostream>

using namespace std;

int n, length, mid, arr[100000], lis[100000];

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
		if (arr[i] > lis[length]) lis[++length] = arr[i];
		else lis[BS(0, length, arr[i])] = arr[i];
	}
	cout << n - length - 1;
}
