//
// Created by Reed Steve on 2024/3/9.
//

#include <iostream>

using namespace std;
int dp[51][51][51][51];

int main() {
    int n, m;
    cin >> n >> m;
    int board[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> board[i];
    }

    int card[5] = {0};
    for (int i = 1, x; i <= m; i++) {
        cin >> x;
        card[x]++;
    }

    for (int i = 0; i <= card[1]; i++) {
        for (int j = 0; j <= card[2]; j++) {
            for (int k = 0; k <= card[3]; k++) {
                for (int o = 0; o <= card[4]; o++) {
                    dp[i][j][k][o] = board[i + 2 * j + 3 * k + 4 * o + 1];
                    int s = 0;
                    if (i) {
                        s = max(s, dp[i - 1][j][k][o]);
                    }
                    if (j) {
                        s = max(s, dp[i][j - 1][k][o]);
                    }
                    if (k) {
                        s = max(s, dp[i][j][k - 1][o]);
                    }
                    if (o) {
                        s = max(s, dp[i][j][k][o - 1]);
                    }
                    dp[i][j][k][o] += s;
                }
            }
        }
    }
    cout << dp[card[1]][card[2]][card[3]][card[4]] << endl;
    return 0;
}