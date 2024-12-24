#include <bits/stdc++.h>
using namespace std;

int n, k, cnt, ans = -1;

void merge(int *arr, int l, int m, int r) {
    int *tmpArr = (int*)malloc((r-l+1) * sizeof(int));
    int i = l, j = m+1, t = 0;
    while(i <= m && j <= r) {
        if(arr[i] <= arr[j]) tmpArr[t++] = arr[i++];
        else tmpArr[t++] = arr[j++];
        cnt++;
        if(cnt == k) ans = tmpArr[t-1];
    }   
    while(i <= m) {
        tmpArr[t++] = arr[i++];
        cnt++;
        if(cnt == k) ans = tmpArr[t-1];
    }
    while(j <= r) {
        tmpArr[t++] = arr[j++];
        cnt++;
        if(cnt == k) ans = tmpArr[t-1];
    }
    i = l, t = 0;
    while(i <= r) arr[i++] = tmpArr[t++];   
}

void mergeSort(int *arr, int l, int r) {
    if(l >= r) return;
    int m = (l+r)/2;
    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);
    merge(arr, l, m, r);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    int *arr = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) cin >> arr[i];
    mergeSort(arr, 0, n-1);
    cout << ans;
}