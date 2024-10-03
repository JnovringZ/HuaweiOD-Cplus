#include <bits/stdc++.h>
using namespace std;
int main() {
    int a1, a2;
    cin >> a1;
    vector<int> v1(a1);
    for (int i = 0; i < a1; i++) {
        cin >> v1[i];
    }

    cin >> a2;
    vector<int> v2(a2);
    for (int i = 0; i < a2; i++) {
        cin >> v2[i];
    }

    int k;
    cin >> k;
    vector<int> nums;

    for (int i = 0; i < v1.size(); i++) {
        for (int j = 0; j < v2.size(); j++) {
            nums.push_back(v1[i] + v2[j]);
        }
    }

    sort(nums.begin(), nums.end());
    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += nums[i];
    }
    cout << sum;
}