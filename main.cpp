//
// Created by Reed Steve on 2024/3/9.
//
#include <iostream>

using namespace std;

int max_loopback(const string &s) {
    int max = s.empty() ? 0 : 1;
    for (int i = 0; i < s.length(); ++i) {
        for (auto j = s.length() - 1; j > i; --j) {
            if (s[j] == s[i]) {
                auto l = max_loopback(s.substr(i + 1, j - i - 1)) + 2;
                if (l > max) {
                    max = l;
                }
            }
        }
    }
    return max;
}

bool solve() {
    string s;
    if (!(cin >> s)) {
        return false;
    }
    cout << max_loopback(s);
    return true;
}

int main() {
    while (solve()) {
        cout << "\n";
    }
    return 0;
}