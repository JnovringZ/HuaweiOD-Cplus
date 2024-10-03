// #include <bits/stdc++.h>
// using namespace std;
// vector<vector<int>> result;  // 存放全部结果
// vector<int> path;
// void backtracking(int n, int k, int startIndex) {
//     if (path.size() == k) {
//         result.push_back(path);
//         return;
//     }

//     for (int i = startIndex; i <= n; i++) {
//         path.push_back(i);
//         backtracking(n, k, i + 1);
//         path.pop_back();  // 回溯
//     }
// }
// // 存放符合条件单个元素
// // vector<vector<int>> combine(int n, int k) {
// //     backtracking(n, k, 1);
// //     return result;
// // }
// int main() {
//     int n, k;
//     cin >> n >> k;
//     // vector<vector<int>> aaa = combine(n, k);
//     backtracking(n, k, 1);
//     // return result;

//     for (int i = 0; i < result.size(); i++) {
//         for (int j = 0; j < k; j++) {
//             cout << result[i][j] << " ";
//         }
//     }
// }

#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> result;
vector<int> path;
int sum = 0;
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
    int n, k;  // n表示数字从1~n; k:一个组合中有k个数
    cin >> n >> k;
    backtracking(n, k, 1);
    
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < k; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < k; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}