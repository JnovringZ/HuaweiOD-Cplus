#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> v;
    int num = 0;
    for (int i = 0; i < N; i++) {
        cin >> num;
        v.push_back(make_pair(num, i));
    }

    stack<pair<int, int>> stackk;
    vector<int> vFlag(N);
    int count = 0;
    int vSize = v.size();
    // stackk.push(v[0]);
    for (int i = 0; i < vSize; i++) {
        if (stackk.empty()) {
            stackk.push(v[i]);
        } else {
            while (!stackk.empty() && v[i].first > stackk.top().first) {
                vFlag[stackk.top().second] = v[i].second;
                stackk.pop();
            }
            stackk.push(v[i]);
        }
    }

    for (int i : vFlag) {
        cout << i << " ";
    }
}
