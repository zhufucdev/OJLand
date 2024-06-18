#include <iostream>

using namespace std;
#define N 100000

int main() {
    int n, m, dp[N], x[N], p[N];
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> p[i] >> x[i];
    int s = 0;
    if (p[0] > 0)
        s = p[0];
    dp[0] = p[0] + x[0];
    for (int i = 0; i < n; i++) {
        if (dp[i] < p[i + 1]) {
            s += p[i + 1] - dp[i];
            dp[i + 1] = p[i + 1] + x[i + 1];
        } else {
            if (dp[i] < p[i + 1] + x[i + 1]) {
                dp[i + 1] = p[i + 1] + x[i + 1];
            } else {
                dp[i + 1] = dp[i];
            }
        }
    }
    if (dp[n - 1] < m) {
        s += m - dp[n - 1];
    }
    cout << s << endl;
}