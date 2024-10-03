#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, end;
    cin >> n >> end;
    vector<pair<int, int>> v(n);  // x,y
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    long long x = 0, y = 0, area = 0;
    for (int i = 0; i < v.size(); i++) {
        long long length = abs(v[i].first - x);
        long long height = abs(y);
        area += length * height;
        // cout << area << " ";
        x = v[i].first;
        y += v[i].second;
    }
    area += (end - x) * abs(y);

    cout << area;
}