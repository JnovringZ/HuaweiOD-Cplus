#include <bits/stdc++.h>
using namespace std;
// int maxLen(vector<int> tree) {
//     int cnt = 0;
//     for (int i = 0; i < tree.size(); i++) {
//         if (tree[i] == 1) {
//             int pos = i;
//             while (tree[i] == 1) {
//                 i++;
//             }
//             int dis = i - pos;
//             cnt = max(cnt, dis);
//         }
//     }
//     return cnt;
// }
int main() {
    int N, die;
    cin >> N;
    cin >> die;
    vector<int> tree(N, 1);
    int a;
    vector<int> dieTree;
    for (int i = 0; i < die; i++) {
        cin >> a;
        dieTree.push_back(a - 1);
        tree[a - 1] = 0;
    }
    int add;
    cin >> add;
    
    int maxLen = 0;
    for (int left = 0; left < tree.size(); left++) {
        int cnt = add;
        for (int right = left; right < tree.size(); right++) {
            if (tree[right] == 1) {
                continue;
            }
            if (tree[right] == 0) {
                if (cnt > 0) {
                    cnt--;
                } else {
                    maxLen = max(maxLen, right - left);
                    break;
                }
            }
        }
    }
    cout << maxLen;
}
