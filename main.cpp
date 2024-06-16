//
// Created by Reed Steve on 2024/3/9.
//

#include <iostream>

using namespace std;
const int N = 1e6;
int f[N], a[N], b[N];

int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}


int main() {
    int t, n, m;
    cin >> t;
    int num = 0;
    while (t--) {
        int ans = 0;
        num++;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            f[i] = i;
            a[i] = 0;
            b[i] = 1;
        }
        while (m--) {
            int x, y;
            cin >> x >> y;
            int u = find(x);
            int v = find(y);
            if (u == v) {
                a[v]++;
            } else {
                f[u] = v;
                a[v] += a[u] + 1;
                b[v] += b[u];
            }
        }
        for (int i = 1; i <= n; i++) {
            if (i == f[i] && (a[i] - b[i] >= 0)) {
                ans += a[i] - b[i];
            }
        }
        cout << "Case #" << num << ": " << ans << endl;
    }

    return 0;
}
