#include <bits/stdc++.h>
using namespace std;
int main() {
    int length;
    cin >> length;

    vector<int> numbers;
    int a;
    for (int i = 0; i < length; i++) {
        cin >> a;
        numbers.push_back(a);
    }
    int N;
    cin >> N;

    vector<int> prefixSum;
    for (int i = 0; i < N; i++) {
        if (i == 0) {
            prefixSum.push_back(numbers[i]);
        } else {
            prefixSum.push_back(prefixSum[i - 1] + numbers[i]);
        }
    }

    for (int i = 0; i < prefixSum.size(); i++) {
        cout << prefixSum[i] << " ";
    }
}