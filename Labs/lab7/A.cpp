#include <iostream>
#include <vector>

using namespace std;

bool isLessOrEqual(string s1, string s2) {
    return s1.size() <= s2.size();
}

void mergeHalves(vector<string> &arr, string temp[], int leftStart, int rightEnd) {
    int leftEnd = (rightEnd + leftStart) / 2;
    int rightStart = leftEnd + 1;

    int left = leftStart;
    int right = rightStart;
    int index = leftStart;

    while (left <= leftEnd && right <= rightEnd) {
        if (isLessOrEqual(arr[left], arr[right])) {
            temp[index] = arr[left];
            left++;
        } else {
            temp[index] = arr[right];
            right++;
        }
        index++;
    }

    while (left <= leftEnd) {
        temp[index] = arr[left];
        index++;
        left++;
    }
    while (right <= rightEnd) {
        temp[index] = arr[right];
        index++;
        right++;
    }
    for (int i = leftStart; i <= rightEnd; i++) {
        arr[i] = temp[i];
    }
}

void mergeSort(vector<string> &arr, string temp[], int leftStart, int rightEnd) {
    if (leftStart >= rightEnd)
        return;
    int middle = (leftStart + rightEnd) / 2;
    mergeSort(arr, temp, leftStart, middle);
    mergeSort(arr, temp, middle + 1, rightEnd);
    mergeHalves(arr, temp, leftStart, rightEnd);
}

int main() {
    int n;
    cin >> n;
    vector<vector<string>> arr(n);
    for (int i = 0; i < n; i++) {
        while (true) {
            string x;
            cin >> x;
            arr[i].push_back(x);
            if (cin.peek() == '\n')
                break;
        }
    }

    for (int i = 0; i < n; i++) {
        int size = arr[i].size();
        string *temp = new string[size]; // Allocate temporary array
        mergeSort(arr[i], temp, 0, size - 1);
        delete[] temp; // Deallocate the temporary array

        for (int j = 0; j < size; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}
