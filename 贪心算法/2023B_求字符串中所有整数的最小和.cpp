#include <bits/stdc++.h>
using namespace std;
int beDevided(string s) {
    int addmin = 0;
    for (int i = 0; i < s.length(); i++) {
        addmin += s[i] - 48;
    }
    return addmin;
}

int main() {
    string s;
    cin >> s;
    int pos;
    int sum = 0;
    for (int i = 0; i < s.length(); i++) {
        if ('0' <= s[i] && s[i] <= '9') {
            pos = i;
            while ('0' <= s[i] && s[i] <= '9') {
                i++;
            }
            // cout << pos << i;
            string ssub = s.substr(pos, i - pos);
            // cout << ssub << endl;
            if (s[pos - 1] == '-') {
                sum -= stoi(ssub);
            } else {
                sum += beDevided(ssub);
            }
        }
    }

    cout << sum;
}