#include<iostream>
#include<algorithm>
using namespace std;

struct Heap{
    long long *a;
    long long size;
    long long capacity;

    Heap(long long val){
        this->a = new long long[val];
        this->size = 0;
        this->capacity = val;
    }

    long long parent(long long i){
        return (i)/2;
    }
    long long leftChild(long long i){
        return 2*i;
    }
    long long rightChild(long long i){
        return 2*i+1;
    }

    void heapifyUp(long long i){
        if(i>0){
            int p = parent(i);
            if(a[i] < a[p]){
                swap(a[i], a[p]);
                heapifyUp(p);
            }
        }
    }
    void heapifyDown(long long i){
        long long  l = leftChild(i);
        long long  r = rightChild(i);
        long long  min = i;

        if(l < this->size && a[min] > a[l]) min = l;
        if(r < this->size && a[min] > a[r]) min = r;

        if(min!=i){
            swap(a[i], a[min]);
            heapifyDown(min);
        }
    }

    void insert(long long val){
        a[size] = val;
        size++;
        heapifyUp(size-1);
    }

    long long print(long long k){
        if(k>size) k = size;
        long long sum =0;
        for(long long i=0; i<k; i++){
            sum+=a[i];
        }
        return sum;
    }

    void cut_min(){
        a[0] = a[size - 1];
        size = max((long long)0, size - 1);
        heapifyDown(0);

    }

};



int main(){
    long long n, k;
    cin >> n >> k;
    Heap heap(k);


    for(long long i=0; i<n; i++){
        string c; cin >> c;
        if(c == "print"){
           cout << heap.print(k) << endl;
        }else if(c == "insert"){
            long long a; cin >> a;
            if(heap.size < k){
                heap.insert(a);
            } else{
            if(a > heap.a[0]){
                heap.cut_min();
                heap.insert(a);
            }}
        }
    }
    return 0;
}