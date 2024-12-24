#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int heapSize = 0;
ll heap[100005];

void swap(ll *a, ll *b) {
    ll tmp = *a;
    *a = *b;
    *b = tmp;
}

int check(int a, int b) {
    if((abs(heap[a]) < abs(heap[b])) || (abs(heap[a]) == abs(heap[b]) && heap[a] < heap[b])) return 1;
    else return 0;
}

void downHeap(int idx) {
    int leftIdx = idx*2, rightIdx = idx*2+1;
    if(leftIdx > heapSize) return;
    int mnIdx = leftIdx;
    if(rightIdx <= heapSize && check(rightIdx, leftIdx)) mnIdx = rightIdx;
    if(check(mnIdx, idx)) {
        swap(&heap[mnIdx], &heap[idx]);
        downHeap(mnIdx);
    }
}

void upHeap(int idx) {
    if(idx/2 < 1) return;
    if(check(idx, idx/2)) {
        swap(&heap[idx], &heap[idx/2]);
        upHeap(idx/2);
    }
}

void insertHeap(ll e) {
    heap[++heapSize] = e;
    upHeap(heapSize);
}

int removeHeap() {
    int rsl = heap[1];
    heap[1] = heap[heapSize];
    heap[heapSize--] = 0;
    downHeap(1);
    return rsl;
}

void printMn() {
    if(heapSize) cout << removeHeap();
    else cout << 0;
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    while(n--) {
        int x; cin >> x;
        if(x) {
            insertHeap(x);
        } else {
            printMn();
        }
    }
}