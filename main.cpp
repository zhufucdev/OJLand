//
// Created by Reed Steve on 2024/3/9.
//
#include <iostream>

using namespace std;

int r_count(int arr[], int tmp[], int len) {
    if (len < 2) {
        return 0;
    } else {
        int middle = len / 2;
        int left = r_count(arr, tmp, middle);
        int right = r_count(arr + middle, tmp + middle, len - middle);
        int spanning = 0;
        int i = 0, j = middle, k = 0;
        while (i < middle && j < len) {
            if (arr[i] <= arr[j]) {
                tmp[k] = arr[i];
                ++i;
            } else {
                tmp[k] = arr[j];
                spanning += middle - i; // Count the inversions
                ++j;
            }
            ++k;
        }
        while (i < middle) { // Copy the remaining elements from the left half
            tmp[k++] = arr[i++];
        }
        while (j < len) { // Copy the remaining elements from the right half
            tmp[k++] = arr[j++];
        }
        copy(tmp, tmp + len, arr);
        return left + right + spanning;
    }
}

bool solve() {
    int n;
    if (!(cin >> n)) {
        return false;
    }
    int *arr = new int[n], *tmp = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << r_count(arr, tmp, n);
    delete[] arr;
    return true;
}

int main() {
    while (solve()) {
        cout << "\n";
    }
    return 0;
}