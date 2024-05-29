//
// Created by Reed Steve on 2024/3/9.
//
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct edge {
    int from, to, len;

    bool operator<(const edge &other) const {
        return len > other.len;
    }
};

struct vertex {
    int num;
    vector<edge> adjs;
};

vector<int> shortest_path(const vector<vertex> &nodes, int begin) {
    vector<int> dest(nodes.size(), INT_MAX);
    vector<bool> visited(nodes.size(), false);
    dest[begin] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> queue;
    queue.emplace(0, begin);
    while (!queue.empty()) {
        auto curr = queue.top();
        auto dis = curr.first;
        auto v = curr.second;
        queue.pop();
        if (visited[v]) continue;
        visited[v] = true;

        for (auto &edge : nodes[v].adjs) {
            auto weight = dis + edge.len;
            if (!visited[edge.to] && weight < dest[edge.to]) {
                dest[edge.to] = weight;
                queue.emplace(weight, edge.to);
            }
        }
    }
    return dest;
}

bool solve() {
    int n, m, x;
    if (!(cin >> n >> m >> x)) {
        return false;
    }
    auto farm_num = x - 1;
    vector<vertex> nodes(n), nodes_reversed(n);
    for (int i = 0, u, v, l; i < m; ++i) {
        cin >> u >> v >> l;
        nodes[u - 1].adjs.push_back({u - 1, v - 1, l});
        nodes_reversed[v - 1].adjs.push_back({v - 1, u - 1, l});
    }
    auto routes = shortest_path(nodes, farm_num);
    auto routes_reversed = shortest_path(nodes_reversed, farm_num);
    int longest = -1;
    for (int i = 0; i < n; ++i) {
        auto curr = routes[i] + routes_reversed[i];
        if (curr > longest) {
            longest = curr;
        }
    }
    cout << longest;
    return true;
}

int main() {
    while (solve()) {
        cout << endl;
    }
    return 0;
}