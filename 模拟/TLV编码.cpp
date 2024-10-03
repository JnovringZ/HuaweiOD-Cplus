#include <bits/stdc++.h>
using namespace std;
int operateing(string left, string right) {
    string ts = right + left;
    int length = stoi(ts, nullptr, 16);
    return length;
}
int main() {
    string tag;
    string ts;
    cin >> tag;
    vector<string> v;
    while (cin >> ts) {
        // cout << ts << " ";
        v.push_back(ts);
        if (cin.get() == '\n') {
            break;
        }
    }

    for (int i = 0; i < v.size(); i++) {
        // cout << v[i] << " ";

        if (v[i] != tag) {
            int length = operateing(v[i + 1], v[i + 2]);
            i = i + 2 + length;
            continue;
        } else {
            int length = operateing(v[i + 1], v[i + 2]);
            for (int j = i + 3; j <= i + 2 + length; j++) {
                cout << v[j] << " ";
            }
            break;
        }
    }
}