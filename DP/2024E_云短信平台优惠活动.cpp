#include <bits/stdc++.h>
using namespace std;
int main() {
    int budget;
    cin >> budget;
    int a;
    vector<int> message;
    vector<int> sale;
    int pos = 1;
    while (cin >> a) {
        message.push_back(a);
        sale.push_back(pos);
        pos++;
        if (cin.get() == '\n')
            break;
    }

    // init
    vector<int> dp(budget + 1, 0);

    // scan
    for (int i = 0; i < sale.size(); i++) {
        for (int j = sale[i]; j <= budget; j++) {
            dp[j] = max(dp[j], dp[j - sale[i]] + message[i]);
        }
    }

    cout << dp.back();
}