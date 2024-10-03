#include <bits/stdc++.h>
using namespace std;
// 3: 153 370 371 407
// 4: 1634 8208 9474
// 5: 54748 92727 93084
// 6: 548834
// 7: 1741725 4210818 9800817 9926315

int main() {
    int n, pos;
    cin >> n >> pos;

    if (7 < n || n < 3) {
        cout << -1 << endl;
        return 0;
    }
    vector<int> v;
    switch (n) {
        case 3:
            v = {153, 370, 371, 407};
            break;
        case 4:
            v = {1634, 8208, 9474};
            break;
        case 5:
            v = {54748, 92727, 93084};
            break;
        case 6:
            v = {548834};
            break;
        case 7:
            v = {1741725, 4210818, 9800817, 9926315};
            break;

        default:
            break;
    }

    if (pos < v.size())
        cout << v[pos];
    else
        cout << v[v.size() - 1] * pos << endl;
    return 0;
}