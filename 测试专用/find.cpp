
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {1, 2, 3, 4, 99};
    int target = 10000;

    string s = "Pineapple";

    auto it = find(nums.begin(), nums.end(), target);
    int its = s.find("7");
    // if (it != nums.end()) {
    // cout << distance(nums.begin(), it) << endl;
    cout << its << endl;
    cout << *nums.end();
    cout << *it;
    // cout << *it;
    // } else {
    //     std::cout << "未找到元素 " << target << std::endl;
    // }

    return 0;
}