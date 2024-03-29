#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int lowerIndex(int arr[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] >= x)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return left;
}

int upperIndex(int arr[], int n, int x) {
    int left = 0, right = n - 1;
    while(left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] <= x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return right;
}

vector <int> nonOverlap(int l1, int r1, int l2, int r2) {
    // l1 r1 range is always a greater range
    if ((r1 - l1) < (r2 - l2)) {
        int tmp = r1;
        r1 = r2;
        r2 = tmp;
        tmp = l1;
        l1 = l2;
        l2 = tmp;
    }
    if (r2 <= r1 && l2 >= l1 )
        return {l1, r1};
    else if (r2 <= r1 && r2 >= l1 && l2 < l1)
        r2 = l1 - 1;
    else if (r2 > r1 && l2 < r1)
        l2 = r1 + 1;
    return{l1, r1, l2, r2};
}

int main() {
    int n, q; cin >> n >> q;
    int v[n];
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v, v+n);
    while(q--) {
        int l1, r1, l2, r2, res;
        cin >> l1 >> r1 >> l2 >> r2;
        vector <int> newRanges = nonOverlap(l1, r1, l2, r2);
        if (newRanges.size() > 2) {
            res = (upperIndex(v, n, newRanges[1]) - lowerIndex(v, n, newRanges[0]) + 1) + (upperIndex(v, n, newRanges[3]) - lowerIndex(v, n, newRanges[2]) + 1);
        }
        else {
            res = upperIndex(v, n, newRanges[1]) - lowerIndex(v, n, newRanges[0]) + 1;
        }
        cout << res << "\n";
    }
}
