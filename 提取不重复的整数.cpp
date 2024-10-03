#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    scanf("%d", &N);
    vector<int> v;
    v.push_back(N % 10);
    int sum = N % 10;
    N /= 10;

    while (N) {
        bool flag = true;
        int temp = N % 10;
        for (int i = 0; i < v.size(); i++) {
            if (temp == v[i]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            v.push_back(temp);
            sum = sum * 10 + temp;
        }
        N /= 10;
    }
    printf("%d", sum);
}
