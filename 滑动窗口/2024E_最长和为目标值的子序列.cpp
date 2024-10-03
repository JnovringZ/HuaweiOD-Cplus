#include <bits/stdc++.h>
using namespace std;
int main() {
    // int a;
    // char sep;
    // vector<int> nums;
    // while (cin >> a) {
    //     nums.push_back(a);
    //     if (cin.get() == '\n')
    //         break;
    // }
    string input;
    getline(cin, input);

    vector<int> nums;
    size_t pos = 0;
    while ((pos = input.find(',')) != string::npos) {
        nums.push_back(stoi(input.substr(0, pos)));
        input.erase(0, pos + 1);
    }
    nums.push_back(stoi(input));
    int target;
    cin >> target;

    // start:
    int maxLen = 0;
    for (int i = 0; i < nums.size(); i++) {
        int sum = 0;
        for (int j = i; j < nums.size(); j++) {
            sum += nums[j];
            if (sum == target) {
                maxLen = max(maxLen, j - i + 1);
            }
            if (sum > target) {
                break;
            }
        }
    }
    cout << maxLen;
}
