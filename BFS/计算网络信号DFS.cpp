#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> grid;
vector<vector<int>> visited;
int endx, endy;
int minstep = 9999;
void dfs(int x, int y, int step, int row, int col) {
    if (x == endx && y == endy) {
        minstep = min(minstep, step);
        return;
    }

    vector<int> dirX = {0, 1, 0, -1};
    vector<int> dirY = {1, 0, -1, 0};
    for (int k = 0; k < 4; k++) {
        int tx = x + dirX[k];
        int ty = y + dirY[k];

        if (tx >= 0 && ty >= 0 && tx < row && ty < col && grid[tx][ty] == 0 && visited[tx][ty] == 0) {
            visited[tx][ty] = 1;
            dfs(tx, ty, step + 1, row, col);
            visited[tx][ty] = 0;
        }
    }
    return;
}
int main() {
    int row, col;
    cin >> row >> col;
    int stx, sty;
    int energy;
    grid.resize(row, vector<int>(col, 0));
    visited.resize(row, vector<int>(col, 0));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> grid[i][j];
            if (grid[i][j] > 0) {
                stx = i;
                sty = j;
                energy = grid[i][j];
            }
        }
    }

    cin >> endx >> endy;

    // for (int i = 0; i < row; i++) {
    //     for (int j = 0; j < col; j++) {
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int step = 0;
    dfs(stx, sty, 0, row, col);
    if (energy >= minstep)
        cout << energy - minstep;
    else
        cout << 0;
}