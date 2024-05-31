#include<iostream>

using namespace std;

long sort(int data[], int tmp[], int l, int m, int r) {
    long num = 0;
    int i = l, k = l;
    int j = m + 1;
    while (i <= m && j <= r) {
        if (data[i] > data[j]) {
            num += m + 1 - i;
            tmp[k++] = data[j++];
        } else {
            tmp[k++] = data[i++];
        }
    }
    while (i <= m) {
        tmp[k++] = data[i++];
    }
    while (j <= r) {
        tmp[k++] = data[j++];
    }
    for (int t = l; t <= r; t++) {
        data[t] = tmp[t];
    }
    return num;
}

long merge(int a[], int b[], int l, int r) {
    long sum = 0;
    if (l < r) {
        int middle = (l + r) / 2;
        sum += merge(a, b, l, middle);
        sum += merge(a, b, middle + 1, r);
        sum += sort(a, b, l, middle, r);
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n], *tmp = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int l = 0, r = n - 1;
    cout << merge(arr, tmp, l, r) << endl;
    return 0;
}