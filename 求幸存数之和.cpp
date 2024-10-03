#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main() {
    vector<int> v;
    int num, jump, left, sum;
    while (cin >> num) {
        v.push_back(num);
        if (cin.get() == '\n')
            break;
    }
    cin >> jump >> left;

    for (auto it = v.begin() + 1;;) {
        if (v.size() == left)
            break;

        for (int i = 0; i < jump; i++) {
            it++;
            if (it == v.end())
                it = v.begin();
        }

        cout << "remove:" << *it << " ";
        auto pos = v.erase(it);
        if (pos == v.end())
            pos = v.begin();
        // cout << "pos:" << *pos << " ";
    }

    for (auto i : v) {
        sum += i;
    }
    cout << sum << endl;
}