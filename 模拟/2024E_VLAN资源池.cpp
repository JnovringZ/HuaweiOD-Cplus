/*
20-21,15,18,30,5-10
15
*/
#include <bits/stdc++.h>
using namespace std;
bool cmp1(pair<string, int>& a, pair<string, int>& b) {
    return a.second < b.second;
}
void paixu(string s, vector<pair<string, int>>& v) {
    int pos = s.find('-');
    int start = 0;
    int end = s.length();
    if (pos == -1) {
        v.push_back(make_pair(s, stoi(s)));
    } else {
        int left = stoi(s.substr(start, pos - start));
        v.push_back(make_pair(s, left));
    }
}
void devided(string s, int vlan, vector<pair<string, int>>& v) {
    int pos = s.find('-');
    int start = 0;
    int end = s.length();

    int left = stoi(s.substr(start, pos - start));
    int right = stoi(s.substr(pos + 1, end - pos - 1));
    vector<int> tv;
    for (int i = left; i <= right; i++) {
        if (i != vlan) {
            tv.push_back(i);
        }
    }

    for (int i = 0; i < tv.size(); i++) {
        pos = i;
        while (tv[i] == tv[i + 1] - 1) {
            i++;
        }
        if (i - pos > 0) {
            string ts = "";
            ts += to_string(tv[pos]);
            ts += '-';
            ts += to_string(tv[i]);
            // cout << ts;
            v.push_back(make_pair(ts, tv[pos]));
        } else {
            v.push_back(make_pair(to_string(tv[pos]), tv[pos]));
        }
    }
}

// 0:不在此字符串范围内, 1:在字符串范围内, 2:在这个点上
int isin(string s, int vlan) {
    int pos = s.find('-');
    int start = 0;
    int end = s.length();
    if (pos == -1) {
        if (stoi(s) == vlan) {
            return 2;
        } else {
            return 0;
        }
    } else {
        int left = stoi(s.substr(start, pos - start));
        int right = stoi(s.substr(pos + 1, end - pos - 1));
        if (left <= vlan && vlan <= right) {
            return 1;
        } else {
            return 0;
        }
    }
}
int main() {
    string s;
    cin >> s;
    s += ',';
    int vlan;
    cin >> vlan;

    int pos = 0;
    vector<pair<string, int>> v;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ',') {
            string ts = s.substr(pos, i - pos);
            pos = i + 1;
            if (isin(ts, vlan) == 0) {
                paixu(ts, v);
            }
            if (isin(ts, vlan) == 1) {
                devided(ts, vlan, v);
                // 拆分
            }
        }
    }

    sort(v.begin(), v.end(), cmp1);
    cout << v[0].first;
    for (int i = 1; i < v.size(); i++) {
        // cout << isin(v[i], vlan) << " ";
        cout << "," << v[i].first;
    }
    // cout << vlan;
}