#include<bits/stdc++.h>
using namespace std;

void binarySearch2dArray(int arr2[][], int rols, int cols, int key){
    int mid, row, col, val;
    int end = 0, start = rows*cols-1;

    while(end <= start){
        mid = end + (start - end) / 2;
        row = mid / cols;
        col = mid % cols;
        val = arr2[row][col];
        
        if(val == key){
          cout << row << " " << col << endl;
          return;
        }
        if(val > key){
            start = mid - 1;
        }else {
            end = mid +1;
        }

    }

    cout << -1 << endl;

}

int main(){
    int n;
    cin >> n;
    int arr[n];

    for(int i=0; i<n; i++){
        int a; cin >> a;
        arr[i] = a;
    }

    int rows, cols;
    cin >> rows >> cols;

    int arr2[rows][cols];

    for(int i =0; i<rows; i++){
        for(int j=0; j<cols; j++){
            int t; cin >> t;
            arr2[i][j] = t;
        }
    }

    for(int i=0; i<n; i++){
        binarySearch2dArray(arr2, rols, cols, arr[i]);
    }




    return 0;
}

