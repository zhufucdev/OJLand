#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;
#define MAX 101

int r, c;
static int h[MAX][MAX];
static int ans[MAX][MAX];
struct info {
    int row;
    int col;
    int value;
};
static vector<info> v;

bool cmp(info x, info y) {
    if (x.value < y.value) return true;
    else
        return false;
}

void update(int x, int y) {
    if (x > 1) {
        if (h[x][y] > h[x - 1][y])
            ans[x][y] = max(ans[x][y], ans[x - 1][y] + 1);
    }
    if (y > 1) {
        if (h[x][y] > h[x][y - 1])
            ans[x][y] = max(ans[x][y], ans[x][y - 1] + 1);
    }
    if (x < r) {
        if (h[x][y] > h[x + 1][y])
            ans[x][y] = max(ans[x][y], ans[x + 1][y] + 1);
    }
    if (y < c) {
        if (h[x][y] > h[x][y + 1])
            ans[x][y] = max(ans[x][y], ans[x][y + 1] + 1);
    }

}

int main() {
    while (scanf("%d %d", &r, &c) != EOF) {
        info read;
        v.clear();
        for (int i = 1; i <= r; i++)
            for (int j = 1; j <= c; j++) {
                read.row = i;
                read.col = j;
                cin >> read.value;
                h[i][j] = read.value;
                ans[i][j] = 1;
                v.push_back(read);
            }

        sort(v.begin(), v.end(), cmp);
        int len = v.size();
        int x, y, value;
        for (int i = 0; i < len; i++) {
            x = v[i].row;
            y = v[i].col;
            value = v[i].value;
            update(x, y);
        }
        int result = 0;
        for (int i = 1; i <= r; i++)
            for (int j = 1; j <= c; j++) {
                if (result < ans[i][j])
                    result = ans[i][j];
            }
        cout << result << endl;
    }
    return 0;
}