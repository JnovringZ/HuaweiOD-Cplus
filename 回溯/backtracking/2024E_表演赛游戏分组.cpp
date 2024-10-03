#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> result;
vector<int> path;
vector<int> ans;
int minFight = 100005;
void backTracking(vector<int> nums, int index, int sum) {
    if (path.size() == 5) {
        int team1 = accumulate(path.begin(), path.end(), 0);
        int team2 = sum - team1;
        minFight = min(minFight, abs(team1 - team2));
        // ans.push_back(team2);
        return;
    }

    for (int i = index; i <= 9; i++) {
        path.push_back(nums[i]);
        backTracking(nums, i + 1, sum);
        path.pop_back();
    }
}
int main() {
    // input
    vector<int> nums(10, 0);
    for (int i = 0; i < 10; i++) {
        cin >> nums[i];
    }

    int sum = accumulate(nums.begin(), nums.end(), 0);
    backTracking(nums, 0, sum);
    for (int i : ans) {
        cout << i << " ";
    }
    cout << minFight;
}