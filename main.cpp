//
// Created by Reed Steve on 2024/3/9.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

void search(vector<int> &ring, vector<bool> &used, int n) {
    if (ring.size() == n && isPrime(ring[0] + ring[n - 1])) {
        for (int i = 0; i < n; ++i) {
            cout << ring[i] << " ";
        }
        cout << endl;
    } else {
        for (int i = 2; i <= n; ++i) {
            if (!used[i] && isPrime(ring[ring.size() - 1] + i)) {
                used[i] = true;
                ring.push_back(i);
                search(ring, used, n);
                used[i] = false;
                ring.pop_back();
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> ring = {1};
    vector<bool> used(n + 1, false);
    used[1] = true;
    search(ring, used, n);
    return 0;
}