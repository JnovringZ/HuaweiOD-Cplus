#include <bits/stdc++.h>
using namespace std;
int main() {
    //如果取到字符串外的内容, 输出换行, 如16行内容
    string s;
    cin >> s;

    for (int i = 0; i < s.length() + 1; i++) {
        cout << s[i];
        int pos = i;
        if (s[pos] <= 'z' && s[pos] >= 'a')
            cout << pos << " ";
    }

    cout << endl;
    cout << s[s.length()] << endl;
}