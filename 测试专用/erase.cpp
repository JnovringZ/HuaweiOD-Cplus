
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    deque<string> fruit{"a", "b", "c", "d", "e"};
    cout << "fruit name :";
    for (int i = 0; i < fruit.size(); i++) {
        cout << fruit[i] << " ";
    }
    cout << '\n';
    fruit.erase(fruit.begin() + 1, fruit.begin() + 3);
    cout << "deleted:," << '\n';
    for (int i = 0; i < fruit.size(); i++) {
        cout << fruit[i] << " ";
    }
    return 0;
}