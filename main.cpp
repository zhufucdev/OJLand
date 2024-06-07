//
// Created by Reed Steve on 2024/3/9.
//
#include <iostream>
using namespace std;

struct DpEle {
    int pos;
    int blunders;
};
DpEle dp[10000][50];

int main() {
    int length, pods_num, speed;
    cin >> length >> pods_num >> speed;
    int pods_pos[pods_num];
    for (int i = 0; i < pods_num; ++i) {
        cin >> pods_pos[i];
    }
    for (int i = 0; i < speed; ++i) {
        dp[0][i] = {1, 0};
    }

    int iter = 1;
    while (true) {
        auto any_change = false;
        auto last = dp[iter - 1][0];
        for (int j = 1; j < speed; ++j) {
            auto curr = dp[iter - 1][j];
            if (curr.blunders < last.blunders || curr.blunders == last.blunders && curr.pos > last.blunders) {
                last = dp[iter - 1][j];
            }
        }
        for (int i = 0; i < speed; ++i) {
            if (last.pos == length) {
                dp[iter][i] = last;
                continue;
            }
            auto will_have_blunder = false;
            auto target_pos = last.pos + i + 1;
            for (int j = 0; j < pods_num; ++j) {
                if (pods_pos[j] == target_pos) {
                    will_have_blunder = true;
                    break;
                }
            }
            dp[iter][i] = DpEle{target_pos, will_have_blunder ? last.blunders + 1 : last.blunders};
            any_change = true;
        }
        if (!any_change) {
            break;
        }
        iter++;
    }

    int least_blunders = length;
    for (int i = 0; i < speed; ++i) {
        if (dp[iter][i].blunders < least_blunders) {
            least_blunders = dp[iter][i].blunders;
        }
    }
    cout << least_blunders << endl;

    return 0;
}