#include<iostream>
#include<algorithm>
using namespace std;

long long sum = 0;

struct Heap{
    long long  *arr;
    long long  size;
    long long  capacity;

    Heap(long long  val){
        this->arr = new long long[val];
        this->size = 0;
        this->capacity  = val;
    }

    long long parent(long long  i){
        return (i-1)/2;
    }
    long long leftChild(long long  i){
        return 2*i+1;
    }
    long long rightChild(long long  i){
        return 2*i+2;
    }

    void heapifyUp(long long  i){
        if(i>0){
            long long p = parent(i);
            if(arr[i] > arr[p]){
                swap(arr[i], arr[p]);
                heapifyUp(p);
            }
        }
    }

    void heapifyDown(long long  i){
        long long  l = leftChild(i);
        long long  r = rightChild(i);
        long long  max = i;

        if(l < this->size && arr[max] < arr[l]) max = l;
        if(r < this->size && arr[max] < arr[r]) max = r;

        if(max!=i){
            swap(arr[i], arr[max]);
            heapifyDown(max);
        }
    }

    void add(long long val){
     arr[size] = val;
        size++;
        heapifyUp(size - 1);
    }

    void cut_max() {
        arr[0] = arr[size - 1];
        size = max((long long)0, size - 1);
        heapifyDown(0);
}

    void check(){
        sum+=arr[0];
        long long num = arr[0]-1;
        cut_max();
        add(num);
    }

};

int main(){
    long long n, k; cin >> n >> k;
    Heap heap(n);

    for(long long i=0; i<n; i++){
        long long a; cin >> a;
        heap.add(a);
    }
    while(k--){
        heap.check();
    }

    cout << sum << endl;



    return 0;
}