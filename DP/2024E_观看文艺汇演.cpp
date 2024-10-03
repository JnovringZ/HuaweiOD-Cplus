#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> performance;
    for (int i = 0; i < n; i++) {
        int start, during;
        cin >> start >> during;
        performance.emplace_back(start, start + during + 15);
    }
    sort(performance.begin(), performance.end());

    // init
    vector<int> dp(n, 0);
    dp[0] = 1;

    for (int i = 1; i < n; i++) {
        int maxGround = 0;
        for (int j = 0; j < i; j++) {
            if (performance[j].second <= performance[i].first) {
                maxGround = max(dp[j], maxGround);
            }
        }
        dp[i] = maxGround + 1;
    }

    cout << dp.back();
}