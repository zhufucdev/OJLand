#include <iostream>

using namespace std;
int ans, vertexes, m;
int col[1010];
int graph[1010][1010];

bool determine(int p, int color) {
    for (int i = 1; i <= vertexes; i++) {
        if (graph[p][i] == 1 && color == col[i]) {
            return false;
        }
    }
    return true;
}

void dfs(int vec) {
    if (vec > vertexes) {
        ans++;
    } else {
        for (int i = 1; i <= m; i++) {
            if (determine(vec, i)) {
                col[vec] = i;
                dfs(vec + 1);
                col[vec] = 0;
            }
        }
    }
}

int main() {
    int k;
    cin >> vertexes >> k >> m;
    for (int i = 1; i <= k; i++) {
        int x, y;
        cin >> x >> y;
        graph[x][y] = 1;
        graph[y][x] = 1;
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}