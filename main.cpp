//
// Created by Reed Steve on 2024/3/9.
//
#include <iostream>
#include <map>

using namespace std;
int A[2000], B[2000], C[2000], D[2000];

int main() {
    int T, n;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int zeros = 0, sum;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> A[i] >> B[i] >> C[i] >> D[i];
        }
        map<int, int> result;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sum = A[i] + B[j];
                ++result[sum];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sum = C[i] + D[j];
                if (result[-sum] > 0) {
                    zeros += result[-sum];
                }
            }
        }
        cout << zeros << endl;
    }
    return 0;
}