#include <bits/stdc++.h>
using namespace std;
bool flag = true;
bool disposable = true;
int main() {
    string s;
    cin >> s;
    regex pattern("^\\d+#\\d+#\\d+#\\d+$");
    if (!regex_match(s, pattern)) {
        flag = false;
    }
    s += '#';
    int pos = 0;
    string val = "";
    for (int i = 0; i < s.length(); i++) {
        // if (!(('1' <= s[i] && s[i] >= '9') || s[i] == '#')) {
        //     flag = false;
        //     break;
        // }

        if (s[i] == '#') {
            string ts = s.substr(pos, i - pos);
            if (disposable) {
                disposable = false;
                if (!(1 <= stoll(ts) && stoll(ts) <= 128))
                    flag = false;
            }
            stringstream ss;
            ss << hex << setfill('0') << setw(2) << stoll(ts);
            ts = ss.str();

            val += ts;
            pos = i + 1;
        }
    }

    if (flag) {
        long long num = stoll(val, nullptr, 16);
        cout << num;
    } else
        cout << "invalid IP";
}