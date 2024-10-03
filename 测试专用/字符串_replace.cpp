#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    // 在字符串第0个位置, 往后选2个字符, 替换成"Hello"
    s.replace(0, 2, "Hello");

    cout << s << endl;
}