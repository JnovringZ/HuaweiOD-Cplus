#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> power(n);
    for (int i = 0; i < n; i++) {
        cin >> power[i];
    }
    int p_max;
    cin >> p_max;

    vector<vector<int>> dp(n, vector<int>(p_max + 1, 0));

    // vector<int> powerCopy(power.begin(), power.end());
    // sort(powerCopy.begin(), powerCopy.end());
    // if (powerCopy[0] > p_max) {
    //     cout << 0 << endl;
    //     return 0;
    // }

    // init
    sort(power.begin(), power.end());
    if (power[0] > p_max) {
        cout << 0 << endl;
        return 0;
    } else {
        for (int i = power[0]; i <= p_max; i++) {
            dp[0][i] = power[0];
        }

        // scan
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= p_max; j++) {
                if (j < power[i]) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - power[i]] + power[i]);
                }
            }
        }

        cout << dp[n - 1][p_max];
        return 0;
    }
}