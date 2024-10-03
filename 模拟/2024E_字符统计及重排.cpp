#include <bits/stdc++.h>
using namespace std;
bool cmp1(pair<char, int>& a, pair<char, int>& b) {
    if (a.second == b.second) {
        if ('a' <= a.first && a.first <= 'z' && 'A' <= b.first && b.first <= 'Z')
            return a.first < b.first + 58;
        if ('A' <= a.first && a.first <= 'Z' && 'a' <= b.first && b.first <= 'z')
            return a.first + 58 < b.first;
        else
            return a.first < b.first;
    } else {
        return a.second > b.second;
    }
}
vector<pair<char, int>> v;  // 字母 : 出现次数
bool found = false;
int main() {
    string s;
    cin >> s;
    v.push_back(make_pair(s[0], 1));
    for (int i = 1; i < s.length(); i++) {
        for (int j = 0; j < v.size(); j++) {
            if (v[j].first == s[i]) {
                // cout << "founded " << s[i] << endl;
                found = true;
                v[j].second++;
                // cout << v[j].first << v[j].second << endl;
                break;
            }
        }
        if (!found) {
            v.push_back(make_pair(s[i], 1));
            // cout << "not found " << s[i] << endl;
        }
        found = false;
    }

    sort(v.begin(), v.end(), cmp1);

    for (int i = 0; i < v.size(); i++) {
        cout << v[i].first << ":" << v[i].second << ";";
    }
}