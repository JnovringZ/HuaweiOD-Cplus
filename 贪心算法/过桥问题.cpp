// https://blog.csdn.net/weixin_43626529/article/details/88569678
#include <bits/stdc++.h>
using namespace std;
int main() {
    int left;
    cin >> left;
    int mins_temp;
    vector<int> v;
    for (int i = 0; i < left; i++) {
        cin >> mins_temp;
        v.push_back(mins_temp);
    }
    sort(v.begin(), v.end());

    int sumMins = 0;
    while (left) {
        if (left == 1) {
            sumMins += v[0];
            break;
        }

        else if (left == 2) {
            sumMins += v[1];
            break;
        }

        else if (left == 3) {
            sumMins += v[0] + v[1] + v[2];
            break;
        }

        else {
            int sumTemp = v[1] + v[0] + v[left - 1] + v[1];
            sumMins += sumTemp;
            left -= 2;
        }
    }

    cout << sumMins << endl;

    // for (auto i : v) {
    //     cout << i << " ";
    // }
}