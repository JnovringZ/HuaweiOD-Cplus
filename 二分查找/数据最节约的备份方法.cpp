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

    sort(nums.begin(), nums.end(), greater<int>());

    int plot = 0;
    vector<int> visited(nums.size(), 0);
    for (int i = 0; i < nums.size(); i++) {
        if (visited[i] == 1)
            continue;

        int cursum = 0;
        plot++;
        int pos = i;
        while (pos < nums.size()) {
            if (visited[pos] == 1) {
                pos++;
                continue;
            }

            if (cursum + nums[pos] > 500) {
                pos++;
            } else if (cursum + nums[pos] <= 500) {
                cursum += nums[pos];
                // cout << cursum << " ";
                visited[pos] = 1;
                // cout << pos << " ";
                pos++;
            }
        }
    }
    cout << plot;
}
