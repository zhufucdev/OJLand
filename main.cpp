#include <iostream>
#include <stack>

using namespace std;

struct map {
public:
    int m, n;
    char grid[50][50];
    bool visited[50][50];
};

struct node {
    int x, y, health;

    node(int _x, int _y, int _health) : x(_x), y(_y), health(_health) {}
};

bool dfs(map &dungeon) {
    auto m = dungeon.m, n = dungeon.n;
    stack<node> sta;
    sta.emplace(0, 0, 3);

    while (!sta.empty()) {
        node node = sta.top();
        sta.pop();
        int x = node.x, y = node.y, health = node.health;

        if (x == m - 1 && y == n - 1) {
            return true;
        }

        if (x < 0 || x >= m || y < 0 || y >= n || dungeon.grid[x][y] == 'W' || health <= 0 || dungeon.visited[x][y]) {
            continue;
        }

        dungeon.visited[x][y] = true;

        if (dungeon.grid[x][y] == 'X') {
            health--;
        }

        sta.emplace(x - 1, y, health);
        sta.emplace(x + 1, y, health);
        sta.emplace(x, y - 1, health);
        sta.emplace(x, y + 1, health);
    }

    return false;
}

int main() {
    int K, M, N;
    cin >> K >> M >> N;

    for (int k = 0; k < K; ++k) {
        map dungeon {M, N};

        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                dungeon.visited[i][j] = false;
            }
        }


        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> dungeon.grid[i][j];
            }
        }

        if (dfs(dungeon)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}