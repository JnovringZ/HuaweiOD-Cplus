// 现在有n阶梯子, 一次可以爬2,3,4阶 有几种爬的方法
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> result;
vector<int> path;
void backtracking(vector<int>& nums, int n, int index) {
    int sum = accumulate(path.begin(), path.end(), 0);
    if (sum == n) {
        result.push_back(path);
        return;
    }
    if (sum > n) {
        return;
    }

    for (int i = index; i < nums.size(); i++) {
        path.push_back(nums[i]);
        backtracking(nums, n, index);
        path.pop_back();
    }
}
int main() {
    int n;
    cin >> n;

    vector<int> nums = {2, 3, 4};
    backtracking(nums, n, 0);
    cout << result.size();
    // for (int i = 0; i < result.size(); i++) {
    //     for (int j = 0; j < result[i].size(); j++) {
    //         cout << result[i][j];
    //     }
    //     cout << endl;
    // }
}