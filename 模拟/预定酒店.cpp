#include <bits/stdc++.h>
using namespace std;
bool cmp1(pair<int, int>& a, pair<int, int>& b) {
    if (a.second == b.second) {
        return a.first < b.first;
    } else
        return a.second < b.second;
}
int main() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<pair<int, int>> v;  // 第一个是价格, 第二个是abs(目标价位-价格)
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        v.push_back(make_pair(temp, abs(temp - x)));
    }

    sort(v.begin(), v.end(), cmp1);

    vector<int> final(k);
    for (int i = 0; i < k; i++) {
        final[i] = v[i].first;
    }
    sort(final.begin(), final.end());
    for (int i = 0; i < final.size(); i++) {
        cout << final[i] << " ";
    }
}