#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> result;
vector<int> path;
void backtracking(int k, int startIndex, int n) {
    if (path.size() == k) {
        int sum = accumulate(path.begin(), path.end(), 0);
        if (sum == n)
            result.push_back(path);

        return;
    }

    for (int i = startIndex; i <= 9; i++) {
        path.push_back(i);
        backtracking(k, i + 1, n);
        path.pop_back();
    }
}
int main() {
    int n, k;
    // k: 一个组合中有k个数字;
    // n: k个数字之和为n
    cin >> k >> n;

    backtracking(k, 1, n);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < k; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}