#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;

    string ss = s;
    sort(ss.begin(), ss.end());

    int pos;
    int exchange1;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ss[i]) {
            exchange1 = i;
            pos = i;
            break;
        }
    }
    for (int i = 0; i < s.length() - 1; i++) {
        if (s[pos] >= s[i + 1])
            pos = i + 1;
    }

    char temp;
    temp = s[exchange1];
    s[exchange1] = s[pos];
    s[pos] = temp;

    // cout << "exchange1:" << exchange1 << endl;
    // cout << "pos:" << pos << endl;
    cout << s << endl;
    // cout << ss << endl;
}
// 输入: abapopabop
// 输出: aaapopbbop