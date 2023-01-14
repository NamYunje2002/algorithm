// https://www.acmicpc.net/problem/1083

#include <iostream>

using namespace std;

int n, s, arr[52];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	cin >> s;

	for (int i = 0; i < n && s > 0; i++) {
		int max = 0, idx = 0;
		
		// i ~ i+s 구간에서 가장 큰 값(max) 구하기
		for (int j = i; j <= s + i && j < n; j++) {
			if (arr[j] > max) {
				max = arr[j];
				idx = j;
			}
		}
		// max가 이미 제일 앞에 있는 경우 건너뛰기
		if (idx == i) 
			continue;
		
		// max보다 앞에 있는 값들을 한 칸씩 뒤로 밀고 max를 i번째에 넣기
		for (int j = idx - 1; j >= i; j--) {
			arr[j + 1] = arr[j];
		}
		arr[i] = max;
		s -= idx - i;
	}
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}
