#include <bits/stdc++.h>
using namespace std;
// lower_bound(): 返回大于或等于目标值的第一个位置
// upper_bound(): 返回大于目标值的第一个位置
// equal_range(): 可以快速方便的定位上界与下界，同样遵循左闭右开的规则
// binary_search(): 若目标值存在则返回true，否则返回false
int main() {
    vector<int> nums = {1, 2, 4, 4, 4, 5, 8, 9, 10, 12, 22};
    auto pos1 = lower_bound(nums.begin(), nums.end(), 11);
    auto pos2 = upper_bound(nums.begin(), nums.end(), 11);
    auto range = equal_range(nums.begin(), nums.end(), 4);
    bool findornot = binary_search(nums.begin(), nums.end(), 99);
    cout << *pos1 << endl;
    cout << *pos2 << endl;
    cout << *range.first << " " << *range.second << endl;
    cout << distance(nums.begin(), range.first) << " " << distance(nums.begin(), range.second) << endl;
    cout << findornot << endl;
}
