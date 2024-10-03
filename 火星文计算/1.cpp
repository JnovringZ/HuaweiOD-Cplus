// https://zhuanlan.zhihu.com/p/645062448
// 7#6$5#12

#include <bits/stdc++.h>
using namespace std;
// #
int xy1(int x, int y) {
    int computed = 4 * x + 3 * y + 2;
    return computed;
}
// $
int xy2(int x, int y) {
    int computed = 2 * x + y + 3;
    return computed;
}

int main() {
    string s;
    cin >> s;

    deque<int> nums;
    deque<char> ops;
    int pos = 0;
    for (int i = 0; i < s[i]; i++) {
        if (s[i] == '#' || s[i] == '$') {
            string ts = s.substr(pos, i - pos);
            int tn = stoi(ts);
            nums.push_back(tn);
            pos = i + 1;
        }

        if (s[i] == '#') {
            ops.push_back(s[i]);
        }

        if (s[i] == '$') {
            
        }
    }

    for (auto i : ops) {
        cout << i << " ";
    }
}