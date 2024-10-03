#include <bits/stdc++.h>
using namespace std;
string unfold(string s) {
    int pos = 0;
    int cnt = 1;
    string ts = "";
    for (int i = 0; i < s.length(); i++) {
        pos = i;
        while (s[i] == s[i + 1]) {
            cnt++;
            i++;
        }
        // cout << cnt;
        if (cnt >= 3) {
            ts += to_string(cnt);
            ts += s[pos];
        }
        if (cnt < 3) {
            for (int j = 0; j < cnt; j++) {
                ts += s[pos];
            }
        }
        cnt = 1;
    }
    // cout << ts << endl;
    return ts;
}

int main() {
    string s;
    cin >> s;
    bool flag = true;
    for (int i = 0; i < s.length(); i++) {
        if (!('0' <= s[i] && s[i] <= '9') && !('a' <= s[i] && s[i] <= 'z')) {
            flag = false;
        }
        if ('0' <= s[s.length() - 1] && s[s.length() - 1] <= '9') {
            flag = false;
        }
    }

    int posPre = 0;
    int posSuf = 0;
    string sfinal = "";
    for (int i = 0; i < s.length(); i++) {
        if ('0' <= s[i] && s[i] <= '9') {
            posSuf = i;
            while ('0' <= s[i] && s[i] <= '9') {
                i++;
            }
            string ts = s.substr(posSuf, i - posSuf);
            // cout << ts << " ";
            // cout << i;

            int num = stoi(ts);
            if (num <= 2) {
                flag = false;
            }

            for (int j = 0; j < num; j++) {
                sfinal += s[i];
            }
            // cout << sfinal << endl;
        } else {
            sfinal += s[i];
        }
    }
    // cout << sfinal << endl;
    if (unfold(sfinal) != s) {
        flag = false;
    }

    if (flag)
        cout << sfinal << endl;
    else
        cout << "!error" << endl;
}