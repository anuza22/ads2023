#include <iostream>
#include <vector>

using namespace std;

int grid[800][800];

int binarySearchIncreasing(int arr[], int target, int size) {
    int left = 0, right = size - 1, mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        else if (target < arr[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

int binarySearchDecreasing(int arr[], int target, int size) {
    int left = 0, right = size - 1, mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        else if (target < arr[mid])
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int findRow(int arr[][800], int target, int numRows, int numCols) {
    int left = 0, right = numRows - 1, mid, min, max;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (mid % 2 == 0) {
            min = arr[mid][numCols - 1];
            max = arr[mid][0];
        } else {
            min = arr[mid][0];
            max = arr[mid][numCols - 1];
        }
        if (target >= min && target <= max) {
            return mid;
        } else if (target < min)
            left = mid + 1;
        else if (target > max)
            right = mid - 1;
    }
    return -1;
}

int main() {
    int t;
    cin >> t;
    vector<int> targets(t);
    for (int i = 0; i < t; i++)
        cin >> targets[i];
    int numCols, numRows;
    cin >> numRows >> numCols;
    
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            cin >> grid[i][j];
        }
    }
    
    for (int i = 0; i < t; i++) {
        int result;
        int row = findRow(grid, targets[i], numRows, numCols);
        if (row == -1) {
            cout << -1 << "\n";
            continue;
        }
        if (row % 2 == 0)
            result = binarySearchDecreasing(grid[row], targets[i], numCols);
        else
            result = binarySearchIncreasing(grid[row], targets[i], numCols);
        if (result != -1)
            cout << row << " " << result << "\n";
        else
            cout << -1 << "\n";
    }
}
