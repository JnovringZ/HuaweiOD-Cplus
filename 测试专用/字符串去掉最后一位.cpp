#include <bits/stdc++.h>
using namespace std;
void headToRear(string& s) {
    char head = s[0];
    s.erase(s.begin());

    s += head;
}
int main() {
    string s = "asdadadfff";
    s.erase(s.end() - 1);

    cout << s << endl;

    headToRear(s);
    cout << s;
}