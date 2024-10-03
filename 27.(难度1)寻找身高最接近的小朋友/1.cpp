// https://www.nowcoder.com/discuss/617297559568015360


#include <bits/stdc++.h>
using namespace std;

bool cmp1(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

int main() {
    int H, N;
    cin >> H >> N;

    vector<pair<int, int>> vAbs_H;
    int childH;
    while (N--) {
        cin >> childH;
        int abss = abs(H - childH);
        vAbs_H.push_back(make_pair(abss, childH));
    }

    sort(vAbs_H.begin(), vAbs_H.end(), cmp1);

    for (int i = 0; i < vAbs_H.size(); i++) {
        cout << vAbs_H[i].second << " ";
    }
}