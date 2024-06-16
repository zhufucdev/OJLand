//
// Created by Reed Steve on 2024/3/9.
//
#include <iostream>
#include <vector>

using namespace std;
const int N = 2000;
int dp[N][N];

int min_distance(const string &w1, const string &w2) {
    auto n = w1.length();
    auto m = w2.length();
    if (n * m == 0) {
        return n + m;
    }

    for (int i = 0; i < n + 1; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j < m + 1; j++) {
        dp[0][j] = j;
    }

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            auto left = dp[i - 1][j] + 1;
            auto down = dp[i][j - 1] + 1;
            auto left_down = dp[i - 1][j - 1];
            if (w1[i - 1] != w2[j - 1]) left_down += 1;
            dp[i][j] = min(left, min(down, left_down));
        }
    }
    return dp[n][m];
}

int main() {
    string w1, w2;
    cin >> w1 >> w2;
    cout << min_distance(w1, w2) << endl;
    return 0;
}