#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    int num;
    set<int> sett;
    int seed;

    int sumMax = 0, sumMin = 0;

    while (N--) {
        cin >> num;
        sett.insert(num);
    }
    cin >> seed;
    int seedDeplicate = seed;
    auto posMin = sett.begin();
    auto posMax = --sett.end();
    vector<int> vMin;
    vector<int> vMax;
    while (seedDeplicate--) {
        vMin.push_back(*posMin);
        sumMin += *posMin;
        posMin++;

        vMax.push_back(*posMax);
        sumMax += *posMax;
        posMax--;
    }

    if (vMin[seed - 1] >= vMax[seed - 1]) {
        cout << -1 << endl;
    } else {
        cout << sumMax + sumMin << endl;
    }
}