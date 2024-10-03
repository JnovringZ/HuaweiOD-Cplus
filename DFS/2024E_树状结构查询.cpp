#include <bits/stdc++.h>
using namespace std;

void dfs(string node, vector<string>& ans, map<string, vector<string>>& relation) {
    ans.push_back(node);
    vector<string> children = relation[node];
    for (string& child : children) {
        dfs(child, ans, relation);
    }
}

int main() {
    vector<string> ans;
    map<string, vector<string>> relation;
    int n;
    cin >> n;
    string child, father;
    for (int i = 0; i < n; i++) {
        cin >> child >> father;
        relation[father].push_back(child);
    }

    string target;
    cin >> target;

    dfs(target, ans, relation);
    sort(ans.begin(), ans.end());

    for (string& node : ans) {
        if (node != target)
            cout << node << endl;
    }
}

// void dfs(char node) {
//     ans.push_back(node);
//     vector<char> children = relation[node];
//     for (int i = 0; i < children.size(); i++) {
//         dfs(children[i]);
//     }
// }
// int main() {
//     int n;
//     cin >> n;

//     for (int i = 0; i < n; i++) {
//         char child, parent;
//         cin >> child >> parent;
//         relation[parent].push_back(child);
//     }

//     char target;
//     cin >> target;

//     dfs(target);

//     sort(ans.begin(), ans.end());
//     for (char node : ans) {
//         if (node != target) {      // 如果节点不是目标节点本身
//             cout << node << endl;  // 输出节点
//         }
//     }
// }