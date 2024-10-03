#include <bits/stdc++.h>
using namespace std;
int upLow = 0;  // 大于0,则大写多, 小于0,则小写多
void upOrLow(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        upLow++;
    } else if (ch >= 'a' && ch <= 'z') {
        upLow--;
    }
}

void changeStr(int flag, string& s) {
    if (flag > 0) {
        transform(s.begin(), s.end(), s.begin(), ::toupper);
    }

    if (flag < 0) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
    }
}
int main() {
    int k;
    string s;
    cin >> k;
    cin >> s;
    int pos = -1;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '-') {
            pos = i + 1;
            break;
        }
    }
    if (pos != -1) {
        int cnt = 0;
        string ts = "";
        string sHead = s.substr(0, pos - 1);
        string sSub = s.substr(pos);
        string sfinal = "";
        for (int i = 0; i < sSub.length(); i++) {
            if (sSub[i] != '-') {
                upOrLow(sSub[i]);
                ts += sSub[i];
                cnt++;
                if (cnt == k) {
                    cnt = 0;
                    changeStr(upLow, ts);
                    upLow = 0;
                    // cout << ts << " " << endl;
                    sHead += '-';
                    sHead += ts;
                    ts = "";
                }
            }
        }
        if (ts != "") {
            changeStr(upLow, ts);
            sHead += '-';
            sHead += ts;
        }
        cout << sHead << endl;
    } else {
        cout << s << endl;
    }
}