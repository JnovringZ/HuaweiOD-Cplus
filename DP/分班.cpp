#include <bits/stdc++.h>
using namespace std;
bool cmp1(pair<int, bool>& a, pair<int, bool>& b) {
    return a.first < b.first;
}
deque<int> children;
deque<string> ynList;
int main() {
    int child;
    char sep, ch;
    while (true) {
        // try 语句，尝试执行以下语句
        try {
            // 进行输入
            string s;
            getline(cin, s);
            // 如果 s 无法进行分割成两部分，则此处解包会出现报错，进入 catch 语句
            int pos = s.find('/');
            int child = stoi(s.substr(0, pos));
            string ch = s.substr(pos + 1);
            // 成功分割，则将小朋友编号记录在 childrenList 中
            // 是否与前一个小朋友同班的标记 "Y" 或 "N" 记录在 ynList 中
            children.push_front(child);
            ynList.push_front(ch);
        }
        // 如果出现错误，说明输入最后一行，退出死循环
        catch (exception& e) {
            break;
        }
    }

    int flag = true;
    vector<pair<int, bool>> class1or2;  // 孩子,true表示同班, false表示不同班
    class1or2.emplace_back(children[0], flag);
    for (int i = 0; i < children.size() - 1; i++) {
        if (ynList[i] == "N") {
            flag = !flag;
            class1or2.emplace_back(children[i + 1], flag);
        } else {
            class1or2.emplace_back(children[i + 1], flag);
        }
    }

    sort(class1or2.begin(), class1or2.end(), cmp1);

    bool tag = class1or2[0].second;
    for (auto i : class1or2) {
        if (i.second == tag) {
            cout << i.first << " ";
        }
    }
    cout << endl;
    for (auto i : class1or2) {
        if (i.second != tag) {
            cout << i.first << " ";
        }
    }
}
