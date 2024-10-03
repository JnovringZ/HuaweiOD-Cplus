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

    // init
    vector<int> dp(time + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int j = time; j >= times[i]; j--) {
            dp[j] = max(dp[j], dp[j - times[i]] + award[i]);
        }
    }

    // for (int i = 0; i < dp.size(); i++) {
    //     cout << dp[i] << " ";
    // }
    cout << dp.back();
}