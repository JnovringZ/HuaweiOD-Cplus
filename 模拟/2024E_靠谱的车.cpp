#include <bits/stdc++.h>
using namespace std;
int main() {
    long long money;
    cin >> money;
    int real = 0;
    int base = 1;
    while (money > 0) {
        int num = money % 10;
        if (num > 4)
            num--;
        real += num * base;
        base *= 9;
        money /= 10;
    }
    cout << real;
}