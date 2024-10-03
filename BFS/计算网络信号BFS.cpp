#include <bits/stdc++.h>
using namespace std;
int endx, endy;
bool flag = false;
vector<vector<int>> grid;
vector<vector<int>> visited;

struct Point {
    int x;
    int y;
    int step;
};

void bfs(int row, int col, queue<Point>& q, int energy) {
    vector<int> dirX = {0, 1, 0, -1};
    vector<int> dirY = {1, 0, -1, 0};
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        if (x == endx && y == endy) {
            if (energy >= q.front().step) {
                cout << energy - q.front().step;
                flag = true;
                break;
            } else {
                cout << 0;
                flag = true;
                break;
            }
        }

        for (int k = 0; k < 4; k++) {
            int tx = x + dirX[k];
            int ty = y + dirY[k];
            if (tx >= 0 && ty >= 0 && tx < row && ty < col && grid[tx][ty] == 0 && visited[tx][ty] == 0) {
                Point temp;
                temp.x = tx;
                temp.y = ty;
                temp.step = q.front().step + 1;
                q.push(temp);
                visited[tx][ty] = 1;
            }
        }
        q.pop();
    }
}

int main() {
    queue<Point> q;
    int row, col;
    cin >> row >> col;
    int stx, sty;
    int energy;
    Point start;
    grid.resize(row, vector<int>(col, 0));
    visited.resize(row, vector<int>(col, 0));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> grid[i][j];
            if (grid[i][j] > 0) {
                start.x = i;
                start.y = j;
                energy = grid[i][j];
            }
        }
    }
    cin >> endx >> endy;
    start.step = 0;
    q.push(start);

    visited[start.x][start.y] = 1;
    bfs(row, col, q, energy);
    if (!flag) {
        cout << 0;
    }
}