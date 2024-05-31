#include <iostream>
#include <algorithm>

using namespace std;

int r_count(int arr[], int tmp[], int left, int right) {
    if (right - left <= 1) {
        return 0;
    } else {
        int middle = (left + right) / 2;
        int left_count = r_count(arr, tmp, left, middle);
        int right_count = r_count(arr, tmp, middle, right);
        int spanning = 0;
        int i = left, j = middle, k = left;
        while (i < middle && j < right) {
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
        while (j < right) { // Copy the remaining elements from the right half
            tmp[k++] = arr[j++];
        }
        copy(tmp + left, tmp + right, arr + left);
        return left_count + right_count + spanning;
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
    cout << r_count(arr, tmp, 0, n);
    delete[] arr;
    return true;
}

int main() {
    while (solve()) {
        cout << "\n";
    }
    return 0;
}