//
// Created by Reed Steve on 2024/3/9.
//

#include <iostream>
#include <vector>

using namespace std;

struct node {
    int depth;
    vector<int> successors;
    node() : depth(-1) {}
};

int depth(node &vertex, node *map) {
    if (vertex.depth > 0) {
        return vertex.depth;
    }
    int max = 0;
    for (auto idx : vertex.successors) {
        int t = depth(map[idx], map);
        if (t > max) {
            max = t;
        }
    }
    vertex.depth = max + 1;
    return max + 1;
}

bool solve() {
    int n, m;
    if (!(cin >> n) || !(cin >> m)) {
        return false;
    }
    node vertexes[m];

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        vertexes[a].successors.push_back(b);
    }

    int max = 0;
    for (auto vertex : vertexes) {
        auto t = depth(vertex, vertexes);
        if (t > max) {
            max = t;
        }
    }

    cout << max;
    return true;
}

int main() {
    while (solve()) {
        cout << endl;
    }
    return 0;
}