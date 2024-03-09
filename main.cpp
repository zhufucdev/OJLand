#include <iostream>
#include <vector>

using namespace std;

int flood_in(int **heightmap, int cols, int rows, int const *start, int min_diff, vector<int> &push_diff) {
    char **f[2] = {new char *[rows], new char *[rows]};

    for (int i = 0; i < rows; ++i) {
        f[0][i] = new char[cols]();
        f[1][i] = new char[cols]();
    }

    auto can_flood_from = [&](int x, int y, int j, int k) {
        auto diff = heightmap[k][j] - heightmap[y][x];
        if (diff <= 0) {
            return false;
        }
        auto found = false;
        for (auto d : push_diff) {
            if (d == diff) {
                found = true;
                break;
            }
        }
        if (!found) {
            push_diff.push_back(diff);
        }
        return diff <= min_diff;
    };

    f[0][start[1]][start[0]] = f[1][start[1]][start[0]] = 1;
    int min_len = 1;
    while (true) {
        auto c = f[min_len % 2], n = f[(min_len + 1) % 2];
        bool has_changes = false;
        for (int y = 0; y < rows; ++y) {
            for (int x = 0; x < cols; ++x) {
                n[y][x] = c[y][x];
                if (!c[y][x]) {
                    if (y > 0 && c[y - 1][x] && can_flood_from(x, y, x, y - 1)
                        || y < rows - 1 && c[y + 1][x] && can_flood_from(x, y, x, y + 1)
                        || x > 0 && c[y][x - 1] && can_flood_from(x, y, x - 1, y)
                        || x < cols - 1 && c[y][x + 1] && can_flood_from(x, y, x + 1, y)) {
                        n[y][x] = 1;
                        has_changes = true;
                    }
                }
#ifdef DEBUG
                cout << (int)n[y][x] << " ";
#endif
            }
#ifdef DEBUG
            cout << "\n";
#endif
        }
#ifdef DEBUG
        cout << "\n";
#endif

        if (!has_changes) {
            break;
        }
        min_len++;
    }

    delete[] f[0];
    delete[] f[1];
    return min_len;
}

int main() {
    int rows, cols, start[3] = {0, 0, -1};
    while (cin >> rows >> cols) {
        int **heightmap = new int *[rows];

        for (int i = 0; i < rows; ++i) {
            heightmap[i] = new int[cols];
            for (int j = 0; j < cols; ++j) {
                cin >> heightmap[i][j];
                if (start[2] < heightmap[i][j]) {
                    start[0] = j;
                    start[1] = i;
                    start[2] = heightmap[i][j];
                }
            }
        }

        vector<int> diff_trial{10000};
        int max_len = 0;
        size_t last_trial = 0;
        do {
#ifdef DEBUG
            cout << diff_trial[last_trial] << ":\n";
#endif
            int l = flood_in(heightmap, cols, rows, start, diff_trial[last_trial++], diff_trial);
            if (l > max_len) {
                max_len = l;
            }
        } while (last_trial < diff_trial.size());

        cout << max_len << endl;

        delete[] heightmap;
    }
}
