#include <bits/stdc++.h>
using namespace std;
void FF(string& s) {
    string ts = "";
    ts += s[0];
    ts += s[1];
    ts += s[4];
    ts += s[5];
    ts += s[3];
    ts += s[2];
    s = ts;
}
void LL(string& s) {
    string ts = "";
    ts += s[4];
    ts += s[5];
    ts += s[2];
    ts += s[3];
    ts += s[1];
    ts += s[0];
    s = ts;
}

void RR(string& s) {
    string ts = "";
    ts += s[5];
    ts += s[4];
    ts += s[2];
    ts += s[3];
    ts += s[0];
    ts += s[1];
    s = ts;
}
void BB(string& s) {
    string ts = "";
    ts += s[0];
    ts += s[1];
    ts += s[5];
    ts += s[4];
    ts += s[2];
    ts += s[3];
    s = ts;
}

void AA(string& s) {
    string ts = "";
    ts += s[3];
    ts += s[2];
    ts += s[0];
    ts += s[1];
    ts += s[4];
    ts += s[5];
    s = ts;
}

void CC(string& s) {
    string ts = "";
    ts += s[2];
    ts += s[3];
    ts += s[1];
    ts += s[0];
    ts += s[4];
    ts += s[5];
    s = ts;
}
// void (string &s){
//     string ts = "";
//     ts += s[];
//     ts += s[];
//     ts += s[];
//     ts += s[];
//     ts += s[];
//     ts += s[];
//     s = ts;
// }
int main() {
    string s;
    cin >> s;
    string origin = "123456";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'F') {
            FF(origin);
        }
        if (s[i] == 'L') {
            LL(origin);
        }
        if (s[i] == 'R') {
            RR(origin);
        }
        if (s[i] == 'C') {
            CC(origin);
        }
        if (s[i] == 'B') {
            BB(origin);
        }
        if (s[i] == 'A') {
            AA(origin);
        }
    }
    cout << origin << endl;
}