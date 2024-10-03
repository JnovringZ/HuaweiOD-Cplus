#include <bits/stdc++.h>
using namespace std;
int main() {
    int row, col;
    cin >> row >> col;
    int arr[100][100];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    /*
    最终结果:
    从上至下是x轴,
    从左至右是y轴
    */
    cout << arr[0][2];
}