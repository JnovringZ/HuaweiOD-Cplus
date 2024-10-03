#include <bits/stdc++.h>
using namespace std;
int main() {
    int k;
    cin >> k;
    string s;
    cin >> s;
    // cout << "\"\"" << endl;
    vector<string> v;
    int pos = 0;
    int poss = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '\"') {
            poss = i;
            i++;
            while (s[i] != '\"') {
                i++;
            }
            i++;
            string ts = s.substr(poss, i - poss);
            v.push_back(ts);
        }

        int pos = i;
        if (s[i] != '_' && s[i] != '\"') {
            while (s[i] != '_' && s[i] != '\"') {
                i++;
            }
            string ts = s.substr(pos, i - pos);
            v.push_back(ts);
        }
    }

    if (k > v.size()) {
        cout << "ERROR" << endl;
    } else {
        v[k] = "******";
        cout << v[0];

        for (int i = 1; i < v.size(); i++) {
            cout << "_" << v[i];
        }
    }
}