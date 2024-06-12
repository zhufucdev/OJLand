//
// Created by Reed Steve on 2024/3/9.
//
#include <iostream>
#include <algorithm>

using namespace std;

int dia_len(int size, int idx) {
    return (size + 1) / 2 - abs((2 * size - 1) / 2 - idx) + 1;
}

pair<int, int> orth_to_dia(int size, int x, int y) {
    return make_pair(, min(x, y) + 1);
}

int main() {
    int n;
    cin >> n;
    int on_primary_dia[n];
    int broken_cells[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {

        }
    }
    return 0;
}