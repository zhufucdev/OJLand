//
// Created by Reed Steve on 2024/3/9.
//
#include <iostream>
#include <queue>
#include <vector>
#include <limits>
#include <map>

using namespace std;

struct vertex {
    int num;
    map<int, int> edges;
};

vector<int> dijsktra(const vector<vertex> &vertexes, int start) {
    vector<int> dis(vertexes.size(), numeric_limits<int>::max());
    vector<bool> visited(vertexes.size(), false);
    dis[start] = 0;

    priority_queue<tuple<int, int>, vector<tuple<int, int>>, greater<>> pq;
    pq.emplace(0, start);
    while (!pq.empty()) {
        auto curr = pq.top();
        pq.pop();

        auto base_distance = get<0>(curr);
        auto to_vertex = get<1>(curr);

        if (visited[to_vertex]) {
            continue;
        }

        visited[to_vertex] = true;

        for (auto &e: vertexes[to_vertex].edges) {
            auto len = e.second + base_distance;
            if (len < dis[e.first]) {
                pq.emplace(len, e.first);
                dis[e.first] = len;
            }
        }
    }
    return dis;
}

struct edge {
    int from;
    int to;
};

int main() {
    int n, edges_num;
    cin >> n >> edges_num;
    vector<vertex> vertexes(n);
    vector<edge> edges(edges_num);

    for (int i = 0; i < edges_num; ++i) {
        int from, to, len;
        cin >> from >> to >> len;
        from -= 1;
        to -= 1;
        vertexes[from].num = from;
        vertexes[from].edges[to] = len;
        edges[i].from = from;
        edges[i].to = to;

        vertexes[to].num = to;
        vertexes[to].edges[from] = len;
    }

    auto x = dijsktra(vertexes, 0)[n - 1];
    auto max_y = 0;
    for (int i = 0; i < edges_num; ++i) {
        vertexes[edges[i].from].edges[edges[i].to] *= 2;
        vertexes[edges[i].to].edges[edges[i].from] *= 2;
        auto y = dijsktra(vertexes, 0)[n - 1];
        if (y < numeric_limits<int>::max() && y > max_y) {
            max_y = y;
        }
        vertexes[edges[i].from].edges[edges[i].to] /= 2;
        vertexes[edges[i].to].edges[edges[i].from] /= 2;
    }

    cout << max_y - x << endl;

    return 0;
}