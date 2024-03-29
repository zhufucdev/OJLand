//
// Created by Reed Steve on 2024/3/9.
//

#include <iostream>

using namespace std;
#define SCALE 100

class DfsSki {
private:
    int heightMap[SCALE][SCALE];
    int cols, rows;

    int dfs(int x, int y, int l) {
        auto r = l;
        auto currH = heightMap[y][x];
        if (heightMap[y][x + 1] < currH && x < cols - 1) {
            r = max(r, dfs(x + 1, y, l + 1));
        }
        if (heightMap[y][x - 1] < currH && x > 0) {
            r = max(r, dfs(x - 1, y, l + 1));
        }
        if (heightMap[y + 1][x] < currH && y < rows - 1) {
            r = max(r, dfs(x, y + 1, l + 1));
        }
        if (heightMap[y - 1][x] < currH && y > 0) {
            r = max(r, dfs(x, y - 1, l + 1));
        }
        return r;
    }

public:
    bool ski() {
        if (!(cin >> rows >> cols)) {
            return false;
        }
        int x = 0, y = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cin >> heightMap[i][j];
                if (heightMap[y][x] < heightMap[i][j]) {
                    x = j;
                    y = i;
                }
            }
        }
        cout << dfs(x, y, 1) << endl;
        return true;
    }
};

int main() {
    while (DfsSki().ski());
    return 0;
}