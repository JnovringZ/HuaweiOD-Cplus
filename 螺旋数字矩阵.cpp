#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, row;
    cin >> n >> row;

    int col;
    if (n % row == 0) {
        col = n / row;
    } else {
        col = n / row + 1;
    }

    // int grid[100][100] = {0};
    vector<vector<string>> grid(row + 1, vector<string>(col + 1, "*"));

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            grid[i][j] = "-";
        }
    }
    // for (int i = 0; i < row + 1; i++) {
    //     for (int j = 0; j < col + 1; j++) {
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    vector<int> dirX = {0, 1, 0, -1};
    vector<int> dirY = {1, 0, -1, 0};
    int dir = 0;
    int x = 0, y = 0;
    int cnt = 2;
    grid[x][y] = "1";
    while (1) {
        if (grid[x + dirX[dir]][y + dirY[dir]] != "-") {
            dir++;
            if (dir == 4) {
                dir = 0;
            }
        }
        x = x + dirX[dir];
        y = y + dirY[dir];
        // cout << x << " " << y << endl;
        if (cnt <= n) {
            grid[x][y] = to_string(cnt);
        } else {
            grid[x][y] = "*";
        }

        cnt++;
        // cout << cnt;
        if (cnt > row * col)
            break;
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}
