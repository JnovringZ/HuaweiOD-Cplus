#include <bits/stdc++.h>
using namespace std;
bool AllbeEaten(vector<int>& nums, int speed, int backTime) {
    int needTime = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] % speed > 0) {
            needTime += nums[i] / speed + 1;
        } else {
            needTime += nums[i] / speed;
        }
        // cout << "needTime: "<<needTime << " ";
    }
    return needTime > backTime;
}

int main() {
    // int a;
    // vector<int> nums;
    // while (cin >> a) {
    //     nums.push_back(a);
    //     if (cin.get() == '\n') {
    //         break;
    //     }
    // }
    // int backTime;
    // cin >> backTime;

    string input;
    getline(cin, input);

    vector<int> nums;
    size_t pos = 0;
    while ((pos = input.find(' ')) != string::npos) {
        nums.push_back(stoi(input.substr(0, pos)));
        input.erase(0, pos + 1);
    }
    nums.push_back(stoi(input));


    int backTime;
    cin >> backTime;

    sort(nums.begin(), nums.end(), greater<int>());

    int left = 1;
    int right = nums.front();
    // cout << AllbeEaten(nums, (left + right) / 2, backTime);
    while (left <= right) {
        int mid = (left + right) / 2;
        if (AllbeEaten(nums, mid, backTime)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << left;
}
