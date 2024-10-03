#include <bits/stdc++.h>
using namespace std;

vector<string> result;
string path;
int cnt = 0;

// true 表示没有字母相邻, false表示有字母相邻
bool ischarAdj(string s) {
    for (int i = 0; i < s.length() - 1; i++) {
        if (s[i] == s[i + 1]) {
            return false;
        }
    }
    return true;
}

void backtracking(int n, string str, int index, vector<bool>& used) {
    if (path.size() == n) {
        if (ischarAdj(path)) {
            cnt++;
            result.push_back(path);
            // cout << path << endl;
        }
        return;
    }

    for (int i = 0; i < str.length(); i++) {
        if (used[i] || path[path.length() - 1] == str[i])
            continue;
        path += str[i];
        used[i] = true;
        // cout << path << endl;
        backtracking(n, str, i, used);
        path.erase(path.end() - 1);
        used[i] = false;
    }
}
int main() {
    string s;
    int N;
    cin >> s;
    cin >> N;
    int flag = true;

    for (int i = 0; i < s.length(); i++) {
        if (!('a' <= s[i] && s[i] <= 'z')) {
            flag = false;
            break;
        }
    }
    if (flag) {
        vector<bool> used(s.length(), false);
        backtracking(N, s, 0, used);
        // cout << cnt << endl;

        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        cout << result.size() << endl;
    } else {
        cout << 0 << endl;
    }
}
