//
// Created by Reed Steve on 2024/3/9.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, minsize, maxsize;
    cin >> minsize >> maxsize;

    auto d = maxsize - minsize + 1;
    auto msize = minsize;
    int mxsize;

    vector<int> vd(d);

    for (int i = 0; i < d; ++i) {
        vd[i] = msize++;
    }
    cin >> n;

    vector<int> vn(n);
    for (int i = 0; i < n; ++i) {
        cin >> vn[i];
    }

    for (auto i: vn) {
        msize = 2 * i;
        mxsize = 10 * i;
        auto j = lower_bound(vd.begin(), vd.end(), msize);
        auto k = upper_bound(vd.begin(), vd.end(), mxsize);
        vd.erase(j, k);
    }

    cout << vd.size() << endl;
    return 0;
}