//
// Created by Reed Steve on 2024/3/9.
//
#include <iostream>
#include <algorithm>

using namespace std;

int dia_len(int size, int idx) {
    return (size * 2 - 1) / 2 - abs((2 * size - 1) / 2 - idx) + 1;
}

pair<int, int> orth_to_dia(int size, int x, int y) {
    int mid_index = (size + 1) / 2;
    return make_pair(x > y ? mid_index - min(x, y) : mid_index + min(x, y), min(x, y) + 1);
}

int backtrace(int *on_primary_dia, bool **cell_dead, int size, int dia_idx) {
    
}

int main() {
    int n;
    cin >> n;
    int on_primary_dia[n];
    bool **cell_broken = new bool *[n];
    for (int i = 0; i < n; ++i) {
        cell_broken[i] = new bool[n];
        for (int j = 0; j < n; ++j) {
            int t;
            cin >> t;
            auto p = orth_to_dia(n, i, j);
            cell_broken[p.first][p.second] = t == 1;
        }
    }

    cout << backtrace(on_primary_dia, cell_broken, n, 0) << endl;

    delete []cell_broken;
    return 0;
}