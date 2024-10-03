#include <bits/stdc++.h>
using namespace std;
// 暴力:
// int main() {
//     int n;
//     cin >> n;
//     vector<int> v(n);
//     for (int i = 0; i < n; i++) {
//         cin >> v[i];
//     }

//     int absMax = 0;
//     for (int i = 0; i < n - 1; i++) {
//         int left = accumulate(v.begin(), v.begin() + 1 + i, 0);
//         int right = accumulate(v.begin() + i + 1, v.end(), 0);
//         // cout << right;
//         absMax = max(absMax, abs(left - right));
//     }

//     cout << absMax;
// }

// 前缀和
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> preSum;
    vector<int> sufSum;
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum += v[i];
        preSum.push_back(sum);
        // cout << sum << " ";
    }
    sum = 0;
    for (int i = n - 1; i > 0; i--) {
        sum += v[i];
        sufSum.push_back(sum);
        // cout << sum << " ";
    }

    int absMax = 0;
    for (int i = 0; i < preSum.size(); i++) {
        int absnum = abs(preSum[i] - sufSum[preSum.size() - 1 - i]);
        absMax = max(absMax, absnum);
    }
    cout << absMax;
}