#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> vv;
    int a;
    while (cin >> a) {
        vv.push_back(a);
        if (cin.get() == '\n') {
            break;
        }
    }
    int origin_length = vv.size();
    vector<int> v;
    for (int i = 0; i < origin_length; i++) {
        v.push_back(vv[i]);
    }
    for (int i = 0; i < origin_length; i++) {
        v.push_back(vv[i]);
    }

    // start:
    stack<pair<int, int>> st;                      // pair<v[i]数值, i下标>
    vector<int> totalPrice(origin_length * 2, 0);  // 原始数组, 价格之和;

    for (int i = 0; i < v.size(); i++) {
        if (st.empty() || st.top().first < v[i]) {
            st.push(make_pair(v[i], i));
        } else {
            while (!st.empty() && st.top().first > v[i]) {
                int sTop = st.top().first;
                int sPos = st.top().second;
                st.pop();
                totalPrice[sPos] = sTop + v[i];
            }
            st.push(make_pair(v[i], i));
        }
    }

    for (int i = 0; i < vv.size(); i++) {
        if (totalPrice[i] > v[i])
            cout << totalPrice[i] << " ";
        else
            cout << vv[i] << " ";
    }
}