#include <bits/stdc++.h>
using namespace std;
int boss;
int findBoss(vector<int>& left, vector<int>& right) {
    bool finded = false;
    for (int i = 0; i < right.size(); i++) {
        auto it = find(left.begin(), left.end(), right[i]);
        if (it == left.end())
            return right[i];
    }
    return -1;
}

int money(int num) {
    return (num / 100) * 15;
}

int dfs(int person, int income, map<int, vector<pair<int, int>>>& relation) {
    // ans.push_back(father);
    int curSum = 0;
    vector<pair<int, int>> children = relation[person];  // 孩子, 收入
    if (children.size() > 0) {
        for (int i = 0; i < children.size(); i++) {
            curSum += dfs(children[i].first, children[i].second, relation);
        }
        curSum += income;
        // cout << curSum << endl;
    } else {
        curSum = income;
    }

    if (person == boss) {
        return curSum;
    } else
        return (curSum / 100) * 15;
}

int main() {
    int n;
    cin >> n;
    int child, father;
    map<int, vector<pair<int, int>>> relation;
    vector<int> left;
    vector<int> right;
    int income;
    for (int i = 0; i < n; i++) {
        cin >> child >> father >> income;
        left.push_back(child);
        right.push_back(father);
        relation[father].emplace_back(child, income);
    }
    boss = findBoss(left, right);
    cout << boss << " " << dfs(boss, 0, relation);
}