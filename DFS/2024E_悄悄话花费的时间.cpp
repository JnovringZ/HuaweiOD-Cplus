#include <bits/stdc++.h>
using namespace std;
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
    vector<int> nums;
    int num;
    while (cin >> num) {
        nums.push_back(num);
        if (cin.get() == '\n')
            break;
    }

    vector<Node*> NodeList(nums.size(), nullptr);
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != -1) {
            NodeList[i] = new Node(nums[i]);
        }
    }

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != -1) {
            if (i * 2 + 1 < nums.size()) {
                NodeList[i]->left = NodeList[i * 2 + 1];
            }
            if (i * 2 + 2 < nums.size()) {
                NodeList[i]->right = NodeList[i * 2 + 2];
            }
        }
    }

    Node* root = NodeList[0];
    dfs(root, 0);

    cout << maxStride;
}
