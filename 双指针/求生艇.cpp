// https://leetcode.cn/problems/boats-to-save-people/description/
#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    int limit;
    cin >> limit;

    int ship = 0;
    auto left = v.begin();
    auto right = v.end() - 1;
    sort(v.begin(), v.end());
    if (v[0] == limit) {
        ship = v.size();
    } else {
        while (right >= left) {
            if (*right == limit) {
                right--;
                ship++;
                cout << "one: " << ship << endl;
            } else if (*right + *left <= limit) {
                right--;
                left++;
                ship++;
                cout << "second: " << ship << endl;
            } else if (*right + *left > limit) {
                right--;
                ship++;
                cout << "third: " << ship << endl;
            }
        }
    }

    cout << ship;

    // for (int i = 0; i < v.size(); i++) {
    //     cout << v[i] << " ";
    // }
}