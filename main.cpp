//
// Created by Reed Steve on 2024/3/9.
//
#include <iostream>

using namespace std;

int count_spanning(const int arr[], int middle, int end);

int count_ends(const int arr[], int len);

int count_ends(const int arr[], int len) {
    if (len < 2) {
        return 0;
    } else if (len == 2) {
        return arr[0] > arr[1];
    } else {
        return count_spanning(arr, len / 2, len);
    }
}

int count_spanning(const int arr[], int middle, int end) {
    int left = count_ends(arr, middle);
    int right = count_ends(arr + middle, end - middle);
    int spanning = 0;
    for (int i = 0; i < middle; ++i) {
        for (int j = middle; j < end; ++j) {
            if (arr[i] > arr[j]) {
                spanning++;
            }
        }
    }
    return left + right + spanning;
}

bool solve() {
    int n;
    if (!(cin >> n)) {
        return false;
    }
    int *arr = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << count_spanning(arr, n / 2, n);
    delete[] arr;
    return true;
}

int main() {
    while (solve()) {
        cout << "\n";
    }
    return 0;
}