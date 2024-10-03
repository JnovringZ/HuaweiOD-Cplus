#include <bits/stdc++.h>
using namespace std;
int main() {
    int time, n;
    cin >> time >> n;
    vector<int> times(n);
    vector<int> award(n);
    for (int i = 0; i < n; i++) {
        cin >> times[i] >> award[i];
    }

    vector<vector<int>> dp(n, vector<int>(time + 1, 0));

    for (int i = times[0]; i <= time; i++) {
        dp[0][i] = award[0];
    }

    // scan
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= time; j++) {
            if (j < times[i]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - times[i]] + award[i]);
            }
        }
    }
    cout << dp[n - 1][time];

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j <= time; j++) {
    //         cout << dp[i][j];
    //     }
    //     cout << endl;
    // }
}