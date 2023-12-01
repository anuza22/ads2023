#include<iostream>
#include<algorithm>
using namespace std;

bool check(int d1[], int d2[]){
    if(d1[2] == d2[2]){
        if(d1[1] == d2[1]){
            return d1[0] < d2[0];
        }else {
            return d1[1] < d2[1];
        }
    }else{
        return d1[2] < d2[2];
    }
}

int partition(int dates[][3], int left, int right, int pivot[]){
    while(left<=right){
        while(check(dates[left], pivot)){
            left++;
        }
        while(check(pivot, dates[right])){
            right--;
        }
        if(left <= right){
            swap(dates[left], dates[right]);
            left++;
            right--;
        }
    }
    return left;
}


void quicksort(int dates[][3], int left, int right){
    if(left>=right) return;

    int pivot[3];
    pivot[0] = dates[(left + right) / 2][0];
    pivot[1] = dates[(left + right) / 2][1];
    pivot[2] = dates[(left + right) / 2][2];
    int index = partition(dates, left, right, pivot);

    quicksort(dates, left, index-1);
    quicksort(dates, index, right);
}

int main(){
    int n, d, m, y; 
    cin >> n;
    int dates[n][3];
    char a;

    for(int i=0; i<n; i++){
        cin >> d >> a >> m  >> a >> y;
        dates[i][0] = d;
        dates[i][1] = m;
        dates[i][2] = y;
    }
    quicksort(dates, 0, n-1);
    for(int i=0; i<n; i++){
        if(dates[i][0] < 10){
            cout << '0';
        }
        cout << dates[i][0] <<'-';
        if(dates[i][1] < 10){
            cout << '0';
        }
        cout << dates[i][1] <<'-' << dates[i][2] << endl;
    }

    return 0;
}