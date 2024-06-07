#include <iostream>
#include <vector>
#include <climits>
#include <unordered_set>

using namespace std;

int minPuddles(int n, int m, int k, vector<int>& puddlePositions) {
    unordered_set<int> puddles(puddlePositions.begin(), puddlePositions.end());
    vector<int> dp(n + 1, INT_MAX);
    dp[1] = puddles.count(1) ? 1 : 0;

    for (int i = 1; i <= n; ++i) {
        if (dp[i] == INT_MAX) continue; // 如果当前位置不可达，跳过
        for (int j = 1; j <= k; ++j) {
            int nextPosition = i + j;
            if (nextPosition > n) break;
            int nextPuddles = dp[i] + (puddles.count(nextPosition) ? 1 : 0);
            if (nextPuddles < dp[nextPosition]) {
                dp[nextPosition] = nextPuddles;
            }
        }
    }

    return dp[n];
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> puddlePositions(m);
    for (int i = 0; i < m; ++i) {
        cin >> puddlePositions[i];
    }

    int result = minPuddles(n, m, k, puddlePositions);
    cout << result << endl;

    return 0;
}
