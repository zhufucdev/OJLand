//
// Created by Reed Steve on 2024/3/9.
//
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 5e3 + 10;

struct node {
    int x, y;
    long long dis;

    bool operator<(const node &b) const {
        return dis < b.dis;
    }
};


int fa[N], tot = 0, Tot = 0;

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void insert_union(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx != fy) {
        fa[fy] = fx, Tot++;
    }
}

node nodes[N * N];

int main() {
    long long x[N], y[N];
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        tot = 0;
        for (int i = 1; i <= n; i++) {
            cin >> x[i] >> y[i];
        }

        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++)
                nodes[++tot] = {i, j, (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])};
        }
        for (int i = 0; i <= n; i++) {
            fa[i] = i;
        }

        sort(nodes + 1, nodes + tot + 1);
        Tot = 0;
        for (int i = 1; i <= tot; i++) {
            insert_union(nodes[i].x, nodes[i].y);
            if (Tot == n - 1) {
                cout << nodes[i].dis << endl;
                break;
            }
        }
    }
}