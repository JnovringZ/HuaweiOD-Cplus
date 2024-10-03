#include <bits/stdc++.h>
using namespace std;
int main() {
    int a;
    vector<int> nums;
    while (cin >> a) {
        nums.push_back(a);
        if (cin.get() == '\n') {
            break;
        }
    }

    int sum = accumulate(nums.begin(), nums.end(), 0);
    int stAver = 128 * nums.size();

    int chaju = abs(sum - stAver);
    int cnt = chaju / nums.size();
    if (sum > stAver) {
        int sum1 = sum - cnt * nums.size();
        int sum2 = sum - (cnt + 1) * nums.size();
        if (abs(sum1 - stAver) < abs(sum2 - stAver)) {
            cout << cnt * (-1);
        } else {
            cout << (cnt + 1) * (-1);
        }
    } else {
        int sum1 = sum + cnt * nums.size();
        int sum2 = sum + (cnt + 1) * nums.size();
        if (abs(sum1 - stAver) < abs(sum2 - stAver)) {
            cout << cnt;
        } else {
            cout << cnt + 1;
        }
    }
}