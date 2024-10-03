#include <bits/stdc++.h>
using namespace std;
bool subQue(vector<int>& nums, int limit, int person) {
    int N = nums.size();
    vector<int> visited(N, 0);
    int block = 0;
    for (int i = 0; i < N; i++) {
        if (visited[i] == 1) {
            continue;
        }
        block++;
        int cursum = 0;
        int j = i;

        while (j < N) {
            if (visited[j] == 1) {
                j++;
                continue;
            } else {
                if (cursum + nums[j] > limit) {
                    j++;
                    continue;
                }
                if (cursum + nums[j] <= limit) {
                    visited[j] = 1;
                    cursum += nums[j];
                    j++;
                }
            }
        }
    }
    return block <= person;
}
int main() {
    int a;
    vector<int> nums;
    while (cin >> a) {
        nums.push_back(a);
        if (cin.get() == '\n') {
            break;
        }
    }
    int person;
    cin >> person;

    sort(nums.begin(), nums.end(), greater<int>());
    int left = nums.front();
    int right = accumulate(nums.begin(), nums.end(), 0);

    // cout << subQue(nums, (left + right) / 2, person);

    while (left <= right) {
        int mid = (left + right) / 2;
        if (subQue(nums, mid, person)) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << left;
}