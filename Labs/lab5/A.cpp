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
    long long  n; cin >> n;
    Heap mainHeap(n);

    long long sumOf2MinVal = 0;

    for(long long i =0; i<n; i++){
        long long  a; cin >> a;
        mainHeap.add(a);
    }

    // for(int i =0; i<n; i++){
    //     cout << mainHeap.arr[i] << " ";
    // }

    while(mainHeap.size > 1){
        long long  f_m = mainHeap.arr[0];
        mainHeap.cut_min();
        long long  s_m = mainHeap.arr[0];
        mainHeap.cut_min();
        long long  sum = f_m+s_m;
        // cout << sum << endl;

        sumOf2MinVal+=sum;
        mainHeap.add(sum);
    }

    cout << sumOf2MinVal << endl;

    return 0;
}