#include <bits/stdc++.h>
using namespace std;
bool cmp1(pair<string, int>& a, pair<string, int>& b) {
    if (a.second == b.second) {
        return a.first < b.first;
    } else {
        return a.second > b.second;
    }
}
int main() {
    int n, m;  // n:学生人数, m:科目数量
    cin >> n >> m;

    vector<string> subject(m);
    for (int i = 0; i < m; i++) {
        cin >> subject[i];
    }

    vector<string> student(n);
    vector<vector<int>> v(n, vector<int>(m));
    vector<pair<string, int>> totalSum;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> student[i];
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
            sum += v[i][j];
        }
        totalSum.push_back(make_pair(student[i], sum));
        sum = 0;
    }
    string tar_sub;
    cin >> tar_sub;

    bool flag = true;
    auto it = find(subject.begin(), subject.end(), tar_sub);
    if (it == subject.end()) {
        flag = false;
        // cout << flag << endl;
    }

    if (flag) {
        int subIndex = distance(subject.begin(), it);
        // cout << subIndex << endl;
        vector<pair<string, int>> aSubScore;
        for (int i = 0; i < v.size(); i++) {
            aSubScore.push_back(make_pair(student[i], v[i][subIndex]));
        }
        sort(aSubScore.begin(), aSubScore.end(), cmp1);
        for (int i = 0; i < aSubScore.size(); i++) {
            cout << aSubScore[i].first << " ";
        }
    } else {
        sort(totalSum.begin(), totalSum.end(), cmp1);
        for (int i = 0; i < totalSum.size(); i++) {
            cout << totalSum[i].first << " ";
        }
    }
}