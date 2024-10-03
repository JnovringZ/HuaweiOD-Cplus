// https://blog.csdn.net/weixin_44052055/article/details/123960335

#include <bits/stdc++.h>
using namespace std;
int main() {
    int a;
    vector<int> v;
    // cin一直输入直到回车结束
    while (cin >> a) {
        v.push_back(a);
        if (cin.get() == '\n')
            break;
    }

    int pos1 = -1;
    int pos2 = -1;
    int count = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == 1) {
            pos1 = i;
            while (v[i] == 1) {
                i++;
            }
            pos2 = i;

            int length = pos2 - pos1;
            cout << length << endl;
            if (length % 3) {
                count += length / 3 + 1;
            } else {
                count += length / 3;
            }
        }
    }
    cout << count << endl;
    // cout << pos2 << endl;
    // for (int i = 0; i < v.size(); i++) {
    //     cout << v[i] << " ";
    // }
}