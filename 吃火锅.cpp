#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> canCatch;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        canCatch.push_back(x + y);
    }

    sort(canCatch.begin(), canCatch.end());

    int obtain = 0;
    int pretime = -m;
    for (int i = 0; i < n; i++) {
        if (canCatch[i] - pretime > m) {
            obtain++;
            pretime = canCatch[i];
        }
    }
    cout << obtain;
}