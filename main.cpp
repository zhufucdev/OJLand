//
// Created by Reed Steve on 2024/3/9.
//

#include <stack>
#include <string>
#include <iostream>

using namespace std;
struct node {
    char value;
    node *left;
    node *right;
};

void postorder(node *root) {
    if (root == nullptr) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->value;
}

void build_btree(node *root, const string &preorder, const string &inorder) {
    int p = -1, q = -1;
    for (int i = 0; i < inorder.length(); ++i) {
        if (inorder[i] == preorder[0]) {
            p = i;
            break;
        }
    }
    for (int i = 0; i < preorder.length(); ++i) {
        for (int j = p + 1; j < inorder.length(); ++j) {
            if (inorder[j] == preorder[i]) {
                q = i;
                break;
            }
        }
        if (q >= 0) {
            break;
        }
    }
    root->value = preorder[0];
    if (p > 0) {
        root->left = new node();
        build_btree(root->left, preorder.substr(1, q - 1), inorder.substr(0, p));
    }
    if (q > 0) {
        root->right = new node();
        build_btree(root->right, preorder.substr(q), inorder.substr(p + 1));
    }
}

bool solve() {
    string inorder, preorder;
    if (!getline(cin, inorder)) {
        return false;
    }
    if (!getline(cin, preorder)) {
        return false;
    }
    stack<char> s;
    node root;
    build_btree(&root, preorder, inorder);
    postorder(&root);
    return true;
}

int main() {
    while (solve()) {
        cout << "\n";
    }
    return 0;
}