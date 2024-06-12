#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> board;
vector<bool> col, diag1, diag2;
int solution_count = 0;

void solve(int row) {
    if (row == n) {
        solution_count++;
        return;
    }

    for (int c = 0; c < n; ++c) {
        if (board[row][c] == 1) continue; // Skip bad cells
        if (!col[c] && !diag1[row - c + n - 1] && !diag2[row + c]) {
            col[c] = diag1[row - c + n - 1] = diag2[row + c] = true;
            solve(row + 1);
            col[c] = diag1[row - c + n - 1] = diag2[row + c] = false;
        }
    }
}

int main() {
    cin >> n;
    board.resize(n, vector<int>(n));
    col.resize(n, false);
    diag1.resize(2 * n - 1, false);
    diag2.resize(2 * n - 1, false);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }

    solve(0);

    cout << solution_count << endl;
    return 0;
}
