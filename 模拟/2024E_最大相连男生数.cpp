#include <bits/stdc++.h>
using namespace std;
int toRight(int x, int y, vector<vector<char>>& grid) {
    int cnt = 1;
    while (grid[x][y] == grid[x][y + 1]) {
        y++;
        cnt++;
    }
    return cnt;
}

int toDown(int x, int y, vector<vector<char>>& grid) {
    int cnt = 1;
    while (grid[x][y] == grid[x + 1][y]) {
        x++;
        cnt++;
    }
    return cnt;
}

int toSlope1(int x, int y, vector<vector<char>>& grid) {
    int cnt = 1;
    while (grid[x][y] == grid[x + 1][y + 1]) {
        x++;
        y++;
        cnt++;
    }
    return cnt;
}

int toSlope2(int x, int y, vector<vector<char>>& grid) {
    int cnt = 1;
    while (grid[x][y] == grid[x + 1][y - 1]) {
        x++;
        y--;
        cnt++;
    }
    return cnt;
}

int main() {
    int row, col;
    char sep;
    cin >> row >> sep >> col;
    vector<vector<char>> grid(row + 1, vector<char>(col + 1, '*'));
    char k;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> grid[i][j];
            if (j < col - 1)
                cin >> sep;
        }
    }

    int cntMax = 0;
    for (int i = 0; i < row + 1; i++) {
        for (int j = 0; j < col + 1; j++) {
            if (grid[i][j] == 'M') {
                int right = toRight(i, j, grid);
                int down = toDown(i, j, grid);
                int slope1 = toSlope1(i, j, grid);
                int slope2 = toSlope2(i, j, grid);
                cntMax = max({cntMax, right, down, slope1, slope2});
            }
        }
    }

    cout << cntMax;
}