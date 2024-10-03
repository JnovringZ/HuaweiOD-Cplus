#include <bits/stdc++.h>
using namespace std;
vector<int> path;
vector<vector<int>> result;
void backtracking(int k, int target, int index) {
    int sum = accumulate(path.begin(), path.end(), 0);
    if (sum == target && path.size() == k) {
        result.push_back(path);
        return;
    }
    if (sum > target) {
        return;
    }

    for (int i = index; i <= 9; i++) {
        path.push_back(i);
        backtracking(k, target, i + 1);
        path.pop_back();
    }
}
int main() {
    int target, k;
    cin >> target >> k;

    backtracking(k, target, 1);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < k; j++) {
            cout << result[i][j];
        }
        cout << endl;
    }
}