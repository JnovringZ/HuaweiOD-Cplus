#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> result;
vector<int> path;
void backtracking(vector<int>& nums, int target, int index) {
    int sum = accumulate(path.begin(), path.end(), 0);
    if (sum == target) {
        result.push_back(path);
        return;
    }
    if (sum > target)
        return;
    for (int i = index; i < nums.size(); i++) {
        path.push_back(nums[i]);
        backtracking(nums, target, i + 1);
        path.pop_back();
    }
}
int main() {
    // input
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

    sort(nums.begin(), nums.end());
    backtracking(nums, target, 0);
    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
        }
        cout << endl;
    }
}