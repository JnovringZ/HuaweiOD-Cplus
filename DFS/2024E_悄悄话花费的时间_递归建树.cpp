#include <bits/stdc++.h>
using namespace std;
vector<int> nums;
int maxStride = 0;

class Node {
   public:
    int val;
    Node* left;
    Node* right;
    Node(int val) {
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};

Node* buildTree(int index) {
    if (index >= nums.size() || nums[index] == -1) {
        return nullptr;
    }

    Node* node = new Node(nums[index]);
    node->left = buildTree(index * 2 + 1);
    node->right = buildTree(index * 2 + 2);
    return node;
}

// void preOrder(Node* root) {
//     if (!root)
//         return;
//     cout << root->val << " ";  // 先访问根节点
//     preOrder(root->left);      // 递归遍历左子树
//     preOrder(root->right);     // 递归遍历右子树
// }

void dfs(Node* node, int path) {
    if (node->left == nullptr && node->right == nullptr) {
        maxStride = max(maxStride, path + node->val);
        // cout << maxStride;
        return;
    }

    if (node->left != nullptr) {
        dfs(node->left, path + node->val);
    }
    if (node->right != nullptr) {
        dfs(node->right, path + node->val);
    }
}

int main() {
    int num;
    while (cin >> num) {
        nums.push_back(num);
        if (cin.get() == '\n')
            break;
    }
    Node* root = buildTree(0);
    // preOrder(root);

    dfs(root, 0);

    cout << maxStride;
    // cout << root->right->left->left->val;
}