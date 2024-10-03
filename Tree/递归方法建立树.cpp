#include <bits/stdc++.h>
using namespace std;
vector<int> nums = {0, 9, 20, -1, -1, 15, 7, -1, -1, -1, -1, 3, 2};
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

Node* bulidTree(int index) {
    if (index >= nums.size() || nums[index] == -1) {
        return nullptr;
    }

    Node* node = new Node(nums[index]);
    node->left = bulidTree(2 * index + 1);
    node->right = bulidTree(2 * index + 2);
    return node;
}

void preOrder(Node* root) {
    if (!root)
        return;
    cout << root->val << " ";  // 先访问根节点
    preOrder(root->left);      // 递归遍历左子树
    preOrder(root->right);     // 递归遍历右子树
}

int main() {
    Node* root = bulidTree(0);
    preOrder(root);
    cout << endl;
}