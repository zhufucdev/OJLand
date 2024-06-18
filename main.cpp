//
// Created by Reed Steve on 2024/3/9.
//

#include<iostream>
#include<algorithm>

using namespace std;
int w[200000], s[200000];

int main() {
    int n, q, sum = 0;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
        sum += w[i];
        w[i] = sum;
    }
    for (int i = 0; i < q; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < q; i++) {
        int *p = lower_bound(w, w + n , s[i]) + 1;
        cout << p - w << " ";
    }
    return 0;
}