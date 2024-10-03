// 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
#include <bits/stdc++.h>
using namespace std;
vector<int> path;
vector<vector<int>> result;
void backtracking(int n, int k, int startIndex) {
    if (path.size() == k) {
        result.push_back(path);
        return;
    }

    for (int i = startIndex; i <= n; i++) {
        path.push_back(i);
        backtracking(n, k, i + 1);
        path.pop_back();
    }
}
int main() {
    int n, k;
    cin >> n >> k;
    backtracking(n, k, 1);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < k; j++) {
            cout << result[i][j];
        }
        cout << endl;
    }
}