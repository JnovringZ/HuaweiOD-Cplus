#include <bits/stdc++.h>
using namespace std;
int maxNum = 0;
int main() {
    int n;
    cin >> n;
    vector<int> block(n);
    for (int i = 0; i < n; i++) {
        cin >> block[i];
    }
    int jump;
    cin >> jump;

    // init
    vector<int> dp(n, 0);
    dp[0] = block[0];
    dp[1] = block[0] + block[1];

    // start
    for (int i = 2; i < n; i++) {
        vector<int> tv;
        for (int j = 1; j <= jump; j++) {
            if (i >= j) {
                int pos = i - j;
                int tnum = dp[pos] + block[i];
                tv.push_back(tnum);
            }
        }
        sort(tv.begin(), tv.end());
        dp[i] = tv[tv.size() - 1];
    }

    // for (auto i : dp) {
    //     cout << i << " ";
    // }
    cout << dp.back();
}