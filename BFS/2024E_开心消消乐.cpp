#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> grid;
queue<pair<int, int>> q;  // x,y
void bfs(int row, int col) {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        vector<int> dirX = {0, 1, 1, 1, 0, -1, -1, -1};
        vector<int> dirY = {1, 1, 0, -1, -1, -1, 0, 1};
        for (int k = 0; k < 8; k++) {
            int tx = x + dirX[k];
            int ty = y + dirY[k];
            if (tx >= 0 && ty >= 0 && tx < row && ty < col && grid[tx][ty] == 1) {
                grid[tx][ty] = 0;
                q.emplace(tx, ty);
            }
        }
        q.pop();
    }
}
int main() {
    int row, col;
    cin >> row >> col;
    grid.resize(row, vector<int>(col, 0));
    vector<pair<int, int>> point;  // x,y: 存放为1的点
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 1) {
                point.emplace_back(i, j);
            }
        }
    }

    int click = 0;
    for (int i = 0; i < point.size(); i++) {
        int x = point[i].first;
        int y = point[i].second;
        if (grid[x][y] == 0)
            continue;

        q.emplace(x, y);
        bfs(row, col);
        click++;
    }
    cout << click;
}