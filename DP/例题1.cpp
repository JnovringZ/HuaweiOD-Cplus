// 背包最大重量为4。
// 物品为：
// 物品 重量 价值
//  0   1    15
//  1   3    20
//  2   4    30
// 问背包能背的物品最大价值是多少？

#include <bits/stdc++.h>
using namespace std;
int main() {
    // int n, bagWeight;
    // cin >> n >> bagWeight;
    int bagCapacity;
    cin >> bagCapacity;
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};

    vector<vector<int>> dp(weight.size(), vector<int>(bagCapacity, 0));

    // init
    for (int i = weight[0]; i <= bagCapacity; i++) {
        dp[0][i] = value[0];
    }

    // for (int i = 0; i < weight.size(); i++) {
    //     for (int j = 0; j <= bagCapacity; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // scan
    for (int i = 1; i < weight.size(); i++) {
        for (int j = 0; j <= bagCapacity; j++) {
            if (j < weight[i]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            }
        }
    }

    cout << dp[2][bagCapacity] << endl;
    for (int i = 0; i < weight.size(); i++) {
        for (int j = 0; j <= bagCapacity; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}