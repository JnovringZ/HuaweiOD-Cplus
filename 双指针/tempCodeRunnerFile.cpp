#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> v;
    int a;
    while (N--) {
        cin >> a;
        v.push_back(a);
    }
    int bottom;
    cin >> bottom;

    sort(v.begin(), v.end());
    int team = 0;

    auto left = v.begin();
    auto right = v.end() - 1;

    while (right > left) {
        if (*right >= bottom) {
            team++;
            right--;
        } else if (*right + *left >= bottom) {
            team++;
            right--;
            left++;
        } else if (*right + *left < bottom) {
            left++;
        }
    }

    cout << team;

    // for (int i = 0; i < v.size(); i++) {
    //     cout << v[i] << " ";
    // }
}