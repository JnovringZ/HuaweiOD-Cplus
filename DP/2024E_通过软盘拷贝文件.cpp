#include <bits/stdc++.h>
using namespace std;
int realSpace(int num) {
    if (num % 512 == 0) {
        return num;
    } else {
        return (num / 512 + 1) * 512;
    }
}
int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> space;  // 占据空间, 文件实际大小
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        int real = realSpace(a);
        space.emplace_back(real, a);
    }

    // for (int i = 0; i < space.size(); i++) {
    //     cout << space[i].first << " " << space[i].second << endl;
    // }

    // init
    vector<int> dp(1474560 + 1, 0);

    // scan
    for (int i = 0; i < space.size(); i++) {
        for (int j = 1474560; j >= space[i].first; j -= 512) {
            dp[j] = max(dp[j], dp[j - space[i].first] + space[i].second);
        }
    }

    // for (int i = 0; i < space.size(); i++) {
    //     cout << space[i].first << " " << space[i].second << endl;
    // }
    cout << dp.back();
}