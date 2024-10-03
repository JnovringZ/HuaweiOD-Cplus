
#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int calHourUsed(vector<int>& nums, int k) {
    int hour = 0;
    for (int p : nums) {
        hour += ceil((double)p / k);
    }
    return hour;
}

int main() {
    string input;
    getline(cin, input);
    string input2;
    getline(cin, input2);

    vector<int> nums;
    size_t pos = 0;
    while ((pos = input.find(' ')) != string::npos) {
        nums.push_back(stoi(input.substr(0, pos)));
        input.erase(0, pos + 1);
    }
    nums.push_back(stoi(input));

    int backTime = stoi(input2);

    // for (int i : nums) {
    //     cout << i << " ";
    // }
    // cout << backTime;

    sort(nums.begin(), nums.end(), greater<int>());
    int left = 1;
    int right = nums.front();

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (calHourUsed(nums, mid) <= backTime) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    if (nums.size() > backTime) {
        cout << 0 << endl;
    } else {
        cout << left << endl;
    }

    return 0;
}