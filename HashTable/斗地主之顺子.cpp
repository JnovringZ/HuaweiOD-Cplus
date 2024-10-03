#include <bits/stdc++.h>
using namespace std;
bool cmp1(pair<string, int>& a, pair<string, int>& b) {
    return a.second < b.second;
}
char numToS(int i) {
    if (i == 13) {
        return 'K';
    }
    if (i == 12) {
        return 'Q';
    }
    if (i == 11) {
        return 'J';
    }
    if (i == 14) {
        return 'A';
    }
    return 0;
}

int main() {
    vector<pair<string, int>> v;
    string s;
    for (int i = 0; i < 13; i++) {
        cin >> s;
        int value = 0;
        if (s == "2")
            continue;
        if ("3" <= s && s <= "9") {
            value = (int)s[0] - 48;
        }
        if (s == "J") {
            value = 11;
        } else if (s == "Q") {
            value = 12;
        } else if (s == "K") {
            value = 13;
        } else if (s == "A") {
            value = 14;
        } else if (s == "10") {
            value = 10;
        }
        v.push_back(make_pair(s, value));
    }
    sort(v.begin(), v.end(), cmp1);

    int cnt = 1;
    vector<int> shunzi;
    int start;
    bool flag = true;
    bool nocout = false;
    for (int i = 0; i < v.size() - 1; i++) {
        if (flag) {
            flag = false;
            start = i;
        }
        if (v[i].second == v[i + 1].second) {
            continue;
        } else {
            if (v[i].second == v[i + 1].second - 1)
                cnt++;
            if (v[i].second < v[i + 1].second - 1) {
                if (cnt >= 5) {
                    nocout = true;
                    // cout << v[i].second << " ";
                    // cout << start;
                    int tt = v[start].second;
                    for (int k = 0; k < cnt; k++) {
                        if (tt >= 11) {
                            cout << numToS(tt) << " ";
                        } else {
                            cout << tt << " ";
                        }
                        tt++;
                    }
                }
                flag = true;
                cnt = 1;
            }
        }
    }

    // cout << cnt << endl;
    // cout << start << endl;
    if (cnt >= 5) {
        nocout = true;
        cout << endl;
        int tt = v[start].second;
        for (int k = 0; k < cnt; k++) {
            if (tt >= 11) {
                cout << numToS(tt) << " ";
            } else {
                cout << tt << " ";
            }
            tt++;
        }
    }

    if (nocout == false) {
        cout << "No" << endl;
    }
}