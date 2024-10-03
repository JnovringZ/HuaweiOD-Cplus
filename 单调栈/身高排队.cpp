// 描叙：有n个人站队，所有的人全部向右看，个子高的可以看到个子低的发型，给出每个人的身高，问所有人能看到其他人发现总和是多少。
// 输入：10,3,7,4,12 输出：4
#include <bits/stdc++.h>
using namespace std;

void FieldSum(vector<int>& v) {
    stack<pair<int, int>> st;  // pair<v[i]的数值, i下标>
    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        if (st.empty() || st.top().first > v[i]) {
            st.push(make_pair(v[i], i));
            // cout << v[i];
        } else {
            int cnt = 0;
            while (st.top().first < v[i] && !st.empty()) {
                int tTop = st.top().first;
                int topPos = st.top().second;
                // cout << tTop << endl;
                st.pop();
                sum += (i - topPos - 1);
                cout << i - topPos - 1 << " ";
            }
            st.push(make_pair(v[i], i));
        }
    }
    cout << sum;
}

int main() {
    vector<int> v = {10, 3, 7, 4, 12};
    FieldSum(v);
    return 0;
}
