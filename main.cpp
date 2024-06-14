//
// Created by Reed Steve on 2024/3/9.
//
#include <iostream>

using namespace std;

#define set_two(mat, x, y, m, n) \
if (x > 0 && x < m && y > 0 && y < n && (!mat[y][x] || mat[y][x] == -1)) { \
    mat_next[y][x] = 2;     \
    any_change = true; \
} \


int main() {
    int n, m;
    cin >> n >> m;

    int **mat = new int *[n];
    for (int i = 0; i < n; ++i) {
        mat[i] = new int[m];
        for (int j = 0; j < m; ++j) {
            cin >> mat[i][j];
        }
    }

    int cx, cy, wx, wy;
    cin >> cx >> cy >> wx >> wy;
    cx--;
    cy--;
    wx--;
    wy--;

    mat[cy][cx] = 2;
    mat[wy][wx] = -1;

    int commands_count = 0;

    bool any_change;
    while (true) {
        any_change = false;
        int **mat_next = new int *[n];
        mat_next[0] = new int[m];

        for (int y = 0; y < n; ++y) {
            if (y < n - 1) {
                mat_next[y + 1] = new int[m];
            }
            for (int x = 0; x < m; ++x) {
                if (mat[y][x] == 2) {
                    set_two(mat, x - 1, y, m, n)
                    set_two(mat, x + 1, y, m, n)
                    set_two(mat, x, y + 1, m, n)
                    set_two(mat, x, y - 1, m, n)
                }
                if (mat[y][x]) {
                    mat_next[y][x] = mat[y][x];
                }
            }
        }

        commands_count++;

        if (mat_next[wy][wx] == 2 || !any_change) {
            delete[]mat_next;
            break;
        }
        delete[]mat;
        mat = mat_next;
    }

    if (any_change) {
        cout << commands_count;
    } else {
        cout << -1;
    }

    return 0;
}