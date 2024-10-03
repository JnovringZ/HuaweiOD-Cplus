#include <bits/stdc++.h>
using namespace std;
int findEle(vector<pair<char, int>>& apperance, char ch) {
    for (int i = 0; i < apperance.size(); i++) {
        if (apperance[i].first == ch) {
            return i;
        }
    }
    return -1;
}

int main() {
    char ch;
    string s;
    cin >> ch;
    cin >> s;
    int maxLen = 0;

    for (int left = 0; left < s.length(); left++) {
        vector<pair<char, int>> apperance;  // 字母, 出现的次数
        int cnt = 0;
        for (int right = left; right < s.length(); right++) {
            if (s[right] == ch)
                break;

            if (s[right] != ch && apperance.empty()) {
                apperance.emplace_back(s[right], 1);
                cnt++;
                continue;
            }
            if (s[right] != ch) {
                // auto it = find(apperance.begin(), apperance.end(), s[right]);
                if (findEle(apperance, s[right]) != -1) {
                    int pos = findEle(apperance, s[right]);
                    if (apperance[pos].second < 2) {
                        apperance[pos].second++;
                        cnt++;
                    }
                } else {
                    apperance.emplace_back(s[right], 1);
                    cnt++;
                }
            }
        }
        // cout << cnt << " ";
        maxLen = max(maxLen, cnt);
    }

    cout << maxLen;
}