//
// Created by Reed Steve on 2024/3/9.
//

#include <iostream>
#include <vector>

using namespace std;

struct node {
    int lchild;
    int rchild;
};

int dfs(const vector<node> &tree, int start) {
    if (start < 1 || start > tree.size() - 1)
        return 0;
    if (!tree[start].lchild && !tree[start].rchild) {
        return 1;
    }
    int left = dfs(tree, tree[start].lchild);
    int right = dfs(tree, tree[start].rchild);
    return left >= right ? left + 1 : right + 1;
}

int main() {
    int n;
    cin >> n;
    vector<node> tree(n + 1, {0, 0});
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        if (!tree[u].lchild) {
            tree[u].lchild = v;
        } else {
            tree[u].rchild = v;
        }
    }

    auto d = dfs(tree, 1) - 1;
    cout << d << endl;
    return 0;
}