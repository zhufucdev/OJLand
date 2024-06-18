//
// Created by Reed Steve on 2024/3/9.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define value_at(x, y) x >= 0 && x < n && y >= 0 && y < n && map[y][x] != 'W' ? dp[y][x] : 0

bool has_solution(int m, int n) {
    vector<string> map(m);
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 0; i < m; ++i) {
        cin >> map[i];
    }

    dp[0][0] = 3;
    while (true) {
        vector<vector<int>> dp_next(m, vector<int>(n, 0));
        bool change = false;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (map[i][j] == 'W') {
                    continue;
                }
                int east = value_at(j + 1, i);
                int south = value_at(j, i + 1);
                int west = value_at(j - 1, i);
                int north = value_at(j, i - 1);
                int max_surrounding = max({east, south, west, north});
                int next = map[i][j] == 'X' ? max_surrounding - 1 : max_surrounding;

                if (next > dp[i][j]) {
                    dp_next[i][j] = next;
                    change = true;
                } else {
                    dp_next[i][j] = dp[i][j];
                }
            }
        }

        dp = dp_next;
        if (!change || dp[m - 1][n - 1] > 0) {
            return dp[m - 1][n - 1] > 0;
        }
    }
}

int main() {
    int k, m, n;
    cin >> k;
    cin >> m >> n;
    for (int i = 0; i < k; ++i) {
        if (has_solution(m, n)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}