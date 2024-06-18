#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int longest(int n, vector<int> &a) {
    if (n == 0) return 0;

    vector<int> dp(n, 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (gcd(a[i], a[j]) == 1) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int result = longest(n, a);
    cout << result << endl;

    return 0;
}
