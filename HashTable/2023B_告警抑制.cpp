#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<pair<string, string>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    string ss;
    vector<string> alarm;
    while (cin >> ss) {
        alarm.push_back(ss);
        if (cin.get() == '\n')
            break;
    }

    // for (int i = 0; i < alarm.size(); i++) {
    //     cout << alarm[i];
    // }

    vector<int> surive(alarm.size(), 1);
    for (int i = 0; i < v.size(); i++) {
        auto first = find(alarm.begin(), alarm.end(), v[i].first);
        // auto second = find(alarm.begin(), alarm.end(), v[i].second);
        // if (first != alarm.end() && second != alarm.end()) {
        //     // cout << "founded" << endl;
        //     // cout << distance(alarm.begin(), first) << " " << *first << endl;
        //     int pos = distance(alarm.begin(), second);
        //     surive[pos] = 0;
        // }
        // cout << *first;
        if (first != alarm.end()) {
            for (int j = 0; j < alarm.size(); j++) {
                if (alarm[j] == v[i].second)
                    surive[j] = 0;
            }
        }
    }
    for (int i = 0; i < alarm.size(); i++) {
        if (surive[i] == 1)
            cout << alarm[i] << " ";
    }
}