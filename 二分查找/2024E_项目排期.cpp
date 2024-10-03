#include <bits/stdc++.h>
using namespace std;
bool subQuestion(int maxK, vector<int>& nums, int numsLen, int person) {
    int scoreBoard = 0;
    vector<int> visited(numsLen, 0);
    for (int i = 0; i < numsLen; i++) {
        if (visited[i] == 1)
            continue;

        scoreBoard++;
        int sum = 0;
        int pos = i;
        while (pos < numsLen) {
            if (visited[pos] == 1) {
                pos++;
                continue;
            }

            if (sum + nums[pos] > maxK) {
                pos++;
            } else {
                sum += nums[pos];
                visited[pos] = 1;
                pos++;
            }
        }
    }
    return scoreBoard <= person;
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
    string input;
    getline(cin, input);

    vector<int> nums;
    size_t pos = 0;
    while ((pos = input.find(' ')) != string::npos) {
        nums.push_back(stoi(input.substr(0, pos)));
        input.erase(0, pos + 1);
    }
    nums.push_back(stoi(input));

    int person;
    cin >> person;
    sort(nums.begin(), nums.end(), greater<int>());
    int left = nums.front();
    int right = accumulate(nums.begin(), nums.end(), 0);

    cout << subQuestion((left + right) / 2, nums, nums.size(), person);
    // while (left <= right) {
    //     int mid = (left + right) / 2;
    //     if (subQuestion(mid, nums, nums.size(), person)) {
    //         right = mid - 1;
    //     } else {
    //         left = mid + 1;
    //     }
    // }

    // cout << left;
}
