// https://jishuzhan.net/article/1732984766996680705

#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> v(N);
int main() {
    // int N;
    cin >> N;
    // vector<int> v(N);
    int a;
    for (int i = 0; i < N; i++) {
        // cin >> v[i];
        cin >> a;
        v.push_back(a);
    }
    int obtain;
    cin >> obtain;

    vector<int> prefixSum(obtain + 1, 0);
    vector<int> suffixSum(obtain + 1, 0);

    for (int i = 0; i < prefixSum.size(); i++) {
        if (i == 0) {
            prefixSum[i] = 0;
            // cout << prefixSum[i];
        } else {
            prefixSum[i] = prefixSum[i - 1] + v[i - 1];
        }
    }

    for (int i = 0, j = v.size() - 1; i < suffixSum.size(); i++) {
        if (i == 0) {
            suffixSum[i] = 0;
            // cout << suffixSum[i];
        } else {
            suffixSum[i] = suffixSum[i - 1] + v[j];
            // cout << v[j];
            j--;
        }
    }
    int maxB = 0;
    for (int i = 0; i <= obtain; i++) {
        int totalB = prefixSum[i] + suffixSum[obtain - i];
        maxB = max(maxB, totalB);
    }

    cout << maxB;

    // for (int i = 0; i < suffixSum.size(); i++) {
    //     cout << suffixSum[i] << " ";
    // }
}