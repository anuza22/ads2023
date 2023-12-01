#include<iostream>
#include<algorithm>
using namespace std;

struct Heap{
    long long  *arr;
    long long  size;
    long long  capacity;

    Heap(long long  val){
        this->arr = new long long[val];
        this->size = 0;
        this->capacity  = val;
    }

    int parent(long long  i){
        return (i-1)/2;
    }
    int leftChild(long long  i){
        return 2*i+1;
    }
    int rightChild(long long  i){
        return 2*i+2;
    }

    void heapifyUp(long long  i){
        if(i>0){
            int p = parent(i);
            if(arr[i] < arr[p]){
                swap(arr[i], arr[p]);
                heapifyUp(p);
            }
        }
    }

    void heapifyDown(long long  i){
        long long  l = leftChild(i);
        long long  r = rightChild(i);
        long long  min = i;

        if(l < this->size && arr[min] > arr[l]) min = l;
        if(r < this->size && arr[min] > arr[r]) min = r;

        if(min!=i){
            swap(arr[i], arr[min]);
            heapifyDown(min);
        }
    }

    void add(long long val){
     arr[size] = val;
        size++;
        heapifyUp(size - 1);
    }

    // void cut_min(){
    //     arr[0] = arr[size-1];
    //     size--;
    //     heapifyDown(0);
    // }

    void cut_min() {
    arr[0] = arr[size - 1];
        size = max((long long)0, size - 1);
        heapifyDown(0);
}

};
int main(){
    long long n, m;
    cin >> n >> m;
    Heap mainHeap(n);

    for(long long i=0; i<n; i++){
        long long a; cin >> a;
        mainHeap.add(a);
    }

    // for(long long i=0; i<n; i++){
    //     cout << mainHeap.arr[i] << " ";
    // }

    long long sum = 0;
    long long cnt = 0;
    // cout << endl;

    while(m >= mainHeap.arr[0]){
        if(mainHeap.size < 2){
            cout << -1 << endl;
            return 0;
        }
        long long x = mainHeap.arr[0];
        mainHeap.cut_min();
        long long y = mainHeap.arr[0];
        mainHeap.cut_min();
        mainHeap.add(x+2*y);
        cnt++;
    }

    cout << cnt << endl;

    return 0;
}

