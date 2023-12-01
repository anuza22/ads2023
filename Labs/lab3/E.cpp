#include<bits/stdc++.h>
using namespace std;

// нерабочий

bool check_Length(vector <pair<int, int>> s, int lenght, int k){
    int cnt = 0;

    for(int i=0; i<s.size(); i++){
        cnt+=(s[i].first /lenght) * (s[i].second/lenght);
        if(cnt>=k) return true;
    }
    return false;
}

int minSideLength(int n, int k,vector <pair<int, int>> s ){
    int left = 1, right = 0;

    for(int i=0; i<n; i++){
        right = max(right, max(s[i].first, s[i].second));
    }

    while(left < right){
        int mid = (left + right)/2;

        if(check_Length(s, mid, k)){
            right = mid;
        } else {
            left = mid + 1;
            }
    }

    return left;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector <pair<int, int>> Coordinate(n);

    for(int i=0; i<n; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        Coordinate[i] = {x2 - x1, y2 - y1};

    }

    int min = minSideLength(n, k, Coordinate);
    cout << min << endl;
}