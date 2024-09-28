#include <bits/stdc++.h>
using namespace std;

int n, k, cnt, ans = -1;
int arr[10005];

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
    cnt++;
    if (cnt == k) {
        for (int i = 0; i < n; i++) cout << arr[i] << ' ';
        ans = 0;
    }
}

int partition(int p, int r) {
    int x = arr[r];
    int i = p-1;
    for (int j = p; j < r; j++) {
        if (arr[j] <= x) swap(&arr[++i], &arr[j]);
    }
    if (i+1 != r) swap(&arr[i+1], &arr[r]);
    return i+1;
}

void quick_sort(int p, int r) {
    if (p < r) {
        int q = partition(p, r);
        quick_sort(p, q-1);
        quick_sort(q+1, r);
    }
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> arr[i];
    quick_sort(0, n-1);
    if (ans == -1) cout << ans;
}