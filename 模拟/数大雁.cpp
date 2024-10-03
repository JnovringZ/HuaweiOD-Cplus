#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;

    // vector<int> bird;
    int bird = 0;
    int cntMax = 0;
    bool flag = true;  // true:有结果, false: -1
    vector<int> birds;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != 'q' && s[i] != 'u' && s[i] != 'a' && s[i] != 'c' && s[i] != 'k') {
            flag = false;
            break;
        }
        if (s[i] == 'q') {
            bird++;
            birds.push_back(bird);
            cntMax = max(cntMax, bird);
        }
        if (s[i] == 'k') {
            bird--;
        }
    }
    if (bird != 0) {
        flag = false;
    }
    
    if (flag)
        cout << cntMax << endl;
    else {
        cout << -1 << endl;
    }
}