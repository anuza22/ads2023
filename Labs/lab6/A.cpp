#include<iostream>
#include<algorithm>
using namespace std;

// int partition(char *arr, int left, int right){
//     char pivot = arr[right];

//     int i = left-1;

//     for(int j=left; j < right)
// }

bool sVowel(char a, char b){
    bool isVowelA = (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u');
    bool isVowelB = (b == 'a' || b == 'e' || b == 'i' || b == 'o' || b == 'u');

    if(isVowelA){
        if(isVowelB) return a<b;
        else return true;
    }else if (isVowelB) return false;
    else return a<b;

}
int partition2(char *a, int left, int right){
    int i = left -1;
    int pivot = right;

    for(int j = left; j<=right-1; j++){
        if(sVowel(a[j], a[pivot])){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[pivot]);
    return i+1;
}

void quicksort(char *arr, int left, int right){
    if(left >= right) return;

    int index = partition2(arr, left, right);
    quicksort(arr, left, index-1);
    quicksort(arr, index+1, right);                                                                                 
}

int main(){
    int n; cin >> n;
    string s; cin >> s;
    char arr[n];

    for(int i=0; i<n; i++){
        arr[i] = s[i];
    }

    quicksort(arr, 0, n-1);

    for(int i=0; i<n; i++){
        cout << arr[i];
    }


    return 0;
}