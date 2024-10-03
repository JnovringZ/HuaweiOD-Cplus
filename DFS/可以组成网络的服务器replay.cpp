#include <bits/stdc++.h>
using namespace std;
int cnt = 1;
void dfs(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& visited, int row, int col) {
    vector<int> dirX = {0, 1, 0, -1};
    vector<int> dirY = {1, 0, -1, 0};

    for (int i = 0; i < 4; i++) {
        int tx = x + dirX[i];
        int ty = y + dirY[i];
        if (tx >= 0 && ty >= 0 && tx < row && ty < col && grid[tx][ty] == 1 && visited[tx][ty] == 0) {
            visited[tx][ty] = 1;
            cnt++;
            // cout << cnt;
            dfs(tx, ty, grid, visited, row, col);
        }
    }
    return;
}

int main() {
    int row, col;
    cin >> row >> col;
    vector<pair<int, int>> point;  // x,y (存入点为1的坐标)
    vector<vector<int>> grid(row + 1, vector<int>(col + 1, -1));
    vector<vector<int>> visited(row, vector<int>(col, 0));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 1) {
                point.emplace_back(i, j);
            }
        }
    }

    // for (int i = 0; i < row; i++) {
    //     for (int j = 0; j < col; j++) {
    //         cout << visited[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int maxConnected = 0;
    for (int i = 0; i < point.size(); i++) {
        int x = point[i].first;
        int y = point[i].second;
        visited[x][y] = 1;
        dfs(x, y, grid, visited, row, col);
        maxConnected = max(maxConnected, cnt);
        cnt = 1;
    }
    // cout << 0;
    cout << maxConnected;
}