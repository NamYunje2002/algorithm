#include <bits/stdc++.h>
using namespace std;

int heapSize;
int mmHeap[1000005];

int isMinLevel(int idx);
void swap(int *a, int *b);
void insertHeap(int num);
void upHeap(int idx);
void upHeapMax(int idx);
void upHeapMin(int idx);
void downHeap(int idx);
int getMaxOrMinFromChild(int idx, bool isMax);
int getMax();
int getMin();
void removeMax();
void removeMin();

int isMinLevel(int idx) {
    return ((int)(log2(idx)) % 2 == 0);
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void insertHeap(int num) {
    mmHeap[++heapSize] = num;
    upHeap(heapSize);
}

void upHeap(int idx) {
    if(idx < 2) return;
    if(isMinLevel(idx)) {
        if(mmHeap[idx] > mmHeap[idx/2]) {
            swap(&mmHeap[idx], &mmHeap[idx/2]);
            upHeapMax(idx/2);
        } else {
            upHeapMin(idx);
        }
    } else {
        if(mmHeap[idx] < mmHeap[idx/2]) {
            swap(&mmHeap[idx], &mmHeap[idx/2]);
            upHeapMin(idx/2);
        } else {
            upHeapMax(idx);
        }
    }
}

void upHeapMax(int idx) {
    if(idx < 4) return;
    if(mmHeap[idx] > mmHeap[idx/4]) {
        swap(&mmHeap[idx], &mmHeap[idx/4]);
        upHeapMax(idx/4);
    }
}

void upHeapMin(int idx) {
    if(idx < 4) return;
    if(mmHeap[idx] < mmHeap[idx/4]) {
        swap(&mmHeap[idx], &mmHeap[idx/4]);
        upHeapMin(idx/4);
    }
}

void downHeap(int idx) {
    if(idx * 2 > heapSize) return;
    
    if(isMinLevel(idx)) {
        int mIdx = getMaxOrMinFromChild(idx, false);
        if(mIdx == idx) return;
        if(mIdx >= idx*4) {
            swap(&mmHeap[mIdx], &mmHeap[idx]);
            if(mmHeap[mIdx] > mmHeap[mIdx/2]) swap(&mmHeap[mIdx], &mmHeap[mIdx/2]);
            downHeap(mIdx);
        } else {
            swap(&mmHeap[mIdx], &mmHeap[idx]);
        }   
    } else {
        int mIdx = getMaxOrMinFromChild(idx, true);
        if(mIdx == idx) return;
        if(mIdx >= idx*4) {
            swap(&mmHeap[mIdx], &mmHeap[idx]);
            if(mmHeap[mIdx] < mmHeap[mIdx/2]) swap(&mmHeap[mIdx], &mmHeap[mIdx/2]);
            downHeap(mIdx);
        } else {
            swap(&mmHeap[mIdx], &mmHeap[idx]);
        }  
    }
}

int getMaxOrMinFromChild(int idx, bool isMax) {
    int rsl = idx;
    int childIdxs[6] = { idx*2, idx*2+1, idx*4, idx*4+1, idx*4+2, idx*4+3 };
    for(auto childIdx : childIdxs) {
        if(childIdx > heapSize) continue;
        if(isMax && mmHeap[childIdx] > mmHeap[rsl]) rsl = childIdx;
        if(!isMax && mmHeap[childIdx] < mmHeap[rsl]) rsl = childIdx;
    }
    return rsl;
}

int getMin() {
    return mmHeap[1];
}

int getMax() {
    if(heapSize == 1) return mmHeap[1];
    else if(heapSize == 2) return mmHeap[2];
    else return max(mmHeap[2], mmHeap[3]);
}

void removeMin() {
    if(heapSize < 1) return;
    mmHeap[1] = mmHeap[heapSize--];
    downHeap(1);
}

void removeMax() {
    if(heapSize < 1) return;
    int idx = 1;
    if(heapSize == 2) idx = 2;
    else idx = (mmHeap[2] > mmHeap[3] ? 2 : 3);
    mmHeap[idx] = mmHeap[heapSize--];
    downHeap(idx);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    
    while(t--) {
        int k; cin >> k;
        
        while(k--) {
            string s; int n;
            cin >> s >> n;
            
            if(s == "I") {
                insertHeap(n);
            }
            else {
                if(n == 1) removeMax();
                else removeMin(); 
            }
        }  
        if(heapSize) cout << getMax() << ' ' << getMin() << '\n';
        else cout << "EMPTY\n";
        heapSize = 0;
    }
}