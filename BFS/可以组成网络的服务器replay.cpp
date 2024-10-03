#include <bits/stdc++.h>
using namespace std;
queue<pair<int, int>> q;  // x,y;
vector<vector<int>> grid;
vector<vector<int>> visited;
int cnt = 1;
void bfs(int row, int col) {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        vector<int> dirX = {0, 1, 0, -1};
        vector<int> dirY = {1, 0, -1, 0};
        for (int k = 0; k < 4; k++) {
            int tx = x + dirX[k];
            int ty = y + dirY[k];

            if (tx >= 0 && ty >= 0 && tx < row && ty < col && grid[tx][ty] == 1 && visited[tx][ty] == 0) {
                cnt++;
                visited[tx][ty] = 1;
                q.emplace(tx, ty);
            }
        }
        q.pop();
    }
}
int main() {
    int row, col;
    cin >> row >> col;
    grid.resize(row + 1, vector<int>(col + 1, -1));
    visited.resize(row, vector<int>(col));
    vector<pair<int, int>> point;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 1) {
                point.emplace_back(i, j);
            }
        }
    }

    int maxConnected = 0;
    for (int i = 0; i < point.size(); i++) {
        int x = point[i].first;
        int y = point[i].second;
        visited[x][y] = 1;
        q.emplace(x, y);
        bfs(row, col);
        maxConnected = max(maxConnected, cnt);
        cnt = 1;
    }
    cout << maxConnected;
}