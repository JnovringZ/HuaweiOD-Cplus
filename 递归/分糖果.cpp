#include <bits/stdc++.h>
using namespace std;
int minStep = 10000000;

void dfs(int n, int step) {
    if (n == 1) {
        minStep = min(minStep, step);
        return;
    }

    if (n % 2 == 0) {
        dfs(n / 2, step + 1);
    } else {
        dfs((n - 1) / 2, step + 2);
        dfs((n + 1) / 2, step + 2);
    }
}
int main() {
    int n;
    cin >> n;
    dfs(n, 0);

    cout << minStep;
}