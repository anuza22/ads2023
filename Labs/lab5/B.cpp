#include<iostream>
#include<algorithm>
using namespace std;

struct Heap{
    long long *arr;
    long long size;
    long long capacity;

    Heap(long long val){
        this->arr = new long long[val];
        this->size = 0;
        this->capacity = val;
    }

    long long parent(long long i){
        return (i-1)/2;
    }
    long long left(long long i){
        return 2*i+1;
    }
    long long right(long long i){
        return 2*i+2;
    }

    void heapToUp(long long i){
        if(i>0){
        long long p = parent(i);
        if(arr[i] < arr[p]){
            swap(arr[i], arr[p]);
            heapToUp(p);
        }
    }
    }

    void heapToDown(long long i){
        long long r = right(i);
        long long l = left(i);
        long long min = i;

        if(l < this->size && arr[min] < arr[l]) min = l;
        if(r < this->size && arr[min] < arr[r]) min = r;

        if(min != i) {
            swap(arr[i], arr[min]);
            heapToDown(min);
        }
    }

    void add(long long val){
        arr[size] = val;
        size++;
        heapToUp(size-1);
    }

    void cut_max(){
        arr[0] = arr[size-1];
        size = max((long long)0, size - 1);
        heapToDown(0);
    }
};

int main(){
    long long n; cin >> n;
    Heap mainHeap(n);

    for(long long i = 0; i<n;i++){
        long long a; cin >> a;
        mainHeap.add(a);
    }

    while(mainHeap.size > 1){
        long long y = mainHeap.arr[0];
        mainHeap.cut_max();
        long long x = mainHeap.arr[0];
        mainHeap.cut_max();

        if(x < y){
            y-=x;
            mainHeap.add(y);
        }else if (x == y) {
            continue;
        }
    }

    if(mainHeap.size > 0) cout << mainHeap.arr[0] << endl;
    else cout << 0 << endl;
    return 0;
}