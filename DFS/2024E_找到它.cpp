#include <bits/stdc++.h>
using namespace std;
vector<string> grid;
vector<vector<int>> visited;
bool flag = false;
int endx, endy;
int stx, sty;
void dfs(int x, int y, int row, int col, string target, int start) {
    if (x == endx && y == endy && start == target.size()) {
        cout << stx + 1 << " " << sty + 1;
        flag = true;
        return;
    }
    vector<int> dirX = {0, 1, 0, -1};
    vector<int> dirY = {1, 0, -1, 0};

    for (int k = 0; k < 4; k++) {
        int tx = x + dirX[k];
        int ty = y + dirY[k];

        if (tx >= 0 && tx < row && ty >= 0 && ty < col && visited[tx][ty] == 0 && grid[tx][ty] == target[start]) {
            visited[tx][ty] = 1;
            dfs(tx, ty, row, col, target, start + 1);
            visited[tx][ty] = 0;
        }
    }
    return;
}
int main() {
    int row, col;
    cin >> row >> col;
    string target;
    cin >> target;

    visited.resize(row, vector<int>(col, 0));
    for (int i = 0; i < row; i++) {
        string ts;
        cin >> ts;
        grid.push_back(ts);
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (grid[i][j] == target[0]) {
                stx = i;
                sty = j;
            }
            if (grid[i][j] == target.back()) {
                endx = i;
                endy = j;
            }
        }
    }
    visited[stx][sty] = 1;
    dfs(stx, sty, row, col, target, 1);
    if (!flag) {
        cout << "NO";
    }
}