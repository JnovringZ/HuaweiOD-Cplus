#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> result;
vector<int> path;
void backtracking(vector<int>& nums, int target, int index) {
    if (accumulate(path.begin(), path.end(), 0) == target) {
        result.push_back(path);
        return;
    }
    if (accumulate(path.begin(), path.end(), 0) > target) {
        return;
    }

    for (int i = index; i < nums.size(); i++) {
        path.push_back(nums[i]);
        backtracking(nums, target, index);
        path.pop_back();
    }
}

int main() {
    string input;
    getline(cin, input);

    vector<int> nums;
    size_t pos = 0;
    while ((pos = input.find(' ')) != string::npos) {
        nums.push_back(stoi(input.substr(0, pos)));
        input.erase(0, pos + 1);
    }
    nums.push_back(stoi(input));
    int target;
    cin >> target;

    // for (int i : nums) {
    //     cout << i << " ";
    // }

    backtracking(nums, target, 0);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}