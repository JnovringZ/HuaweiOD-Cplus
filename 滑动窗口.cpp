#include <bits/stdc++.h>
using namespace std;
void getMaxMin(vector<int> v, vector<int>& vMin, vector<int>& vMax) {
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    vMin.push_back(v[0]);
    vMax.push_back(v[v.size() - 1]);
}

int main() {
    int n, k;  // n:数组长度, k:滑窗长度
    cin >> n >> k;

    vector<int> arr;
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        arr.push_back(a);
    }

    vector<int> vMin, vMax, v;
    int count = 0;
    int pos;
    for (int i = 0; i < arr.size() - k + 1; i++) {
        pos = i;
        while (count < k) {
            v.push_back(arr[pos]);
            // cout << arr[pos] << " ";
            pos++;
            count++;
        }
        count = 0;
        getMaxMin(v, vMin, vMax);
        // for (int i = 0; i < v.size(); i++) {
        //     cout << v[i] << " ";
        // }
        // cout << endl;
        v.clear();
        pos = -1;
    }

    for (int i = 0; i < vMin.size(); i++) {
        cout << vMin[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < vMax.size(); i++) {
        cout << vMax[i] << " ";
    }
}