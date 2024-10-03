#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    int n;
    // cin >> s >> n;
    scanf("%s %d", &s, &n);

    string totals;
    for (int i = 0; i < n; i++) {
        totals += s[i];
    }

    // printf("%s", totals);
    cout << totals << endl;
    // cout << n << endl;
}