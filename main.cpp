//
// Created by Reed Steve on 2024/3/9.
//

#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

const int N = 200;
const int INF = numeric_limits<int>::max();
int weights[N][N];

inline void read_graph(int m) {
    for (int i = 1; i < N; ++i) {
        weights[i][i] = INF;
        for (int j = i + 1; j < N; ++j) {
            weights[i][j] = weights[j][i] = INF;
        }
    }
    int a, b, c;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        weights[a][b] = weights[b][a] = c;
    }
}

inline void floyd(int n) {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                int tmp = max(weights[i][k], weights[k][j]);
                weights[i][j] = min(weights[i][j], tmp);
            }
        }
    }
}

int main() {
    int case_num = 0, n, m, q;
    while (cin >> n >> m >> q) {
        if (!n && !m && !q) {
            break;
        }
        read_graph(m);
        floyd(n);

        cout << "Case #" << ++case_num << endl;
        int u, v;
        for (int i = 0; i < q; ++i) {
            cin >> u >> v;
            if (weights[u][v] != INF) {
                cout << weights[u][v] << endl;
            } else {
                cout << "no path" << endl;
            }
        }
    }
    return 0;
}
