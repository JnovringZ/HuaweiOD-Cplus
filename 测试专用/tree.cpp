#include <iostream>
#include <vector>
using namespace std;
int maxDeep = 1;
class Node {
   public:
    int val;
    Node* left;
    Node* mid;
    Node* right;
    Node(int val) {
        this->val = val;
        left = nullptr;
        mid = nullptr;
        right = nullptr;
    }
};

void buildTree(Node* curnode, vector<int>& nums, int index) {
    if (nums[index] < curnode->val - 500) {
        if (curnode->left == nullptr) {
            curnode->left = new Node(nums[index]);
            return;
        }
        buildTree(curnode->left, nums, index);
    } else if (nums[index] > curnode->val + 500) {
        if (curnode->right == nullptr) {
            curnode->right = new Node(nums[index]);
            return;
        }
        buildTree(curnode->right, nums, index);
    } else {
        if (curnode->mid == nullptr) {
            curnode->mid = new Node(nums[index]);
            return;
        }
        buildTree(curnode->mid, nums, index);
    }
}

void dfs(Node* node, int deep) {
    if (!node->left && !node->mid && !node->right) {
        maxDeep = max(maxDeep, deep);
        return;
    }

    if (node->left) {
        dfs(node->left, deep + 1);
    }
    if (node->mid) {
        dfs(node->mid, deep + 1);
    }
    if (node->right) {
        dfs(node->right, deep + 1);
    }
}

// int main() {
//     int n;
//     cin >> n;
//     vector<int> nums(n);

//     for (int i = 0; i < n; i++) {
//         cin >> nums[i];
//     }

//     Node* root = new Node(nums[0]);

//     for (int i = 1; i < n; i++) {
//         buildTree(root, nums, i);
//     }

//     dfs(root, 1);

//     cout << maxDeep << endl;

//     return 0;
// }

int main() {
    int n;

    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    Node* root = new Node(nums[0]);
    for (int i = 1; i < n; i++) {
        buildTree(root, nums, i);
    }

    dfs(root, 1);
    cout << maxDeep;
}
