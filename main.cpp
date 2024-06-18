//
// Created by Reed Steve on 2024/3/9.
//
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int kills[n + 1];
    for (int i = 1; i <= n; ++i) {
        cin >> kills[i];
    }
    int dp[n];
    dp[0] = 0;
    dp[1] = kills[1];
    dp[2] = kills[2];
    for (int i = 3; i <= n; ++i) {
        dp[i] = max(dp[i - 2], dp[i - 3]) + kills[i];
    }
    cout << max(dp[n], dp[n - 1]) << endl;
    return 0;
}