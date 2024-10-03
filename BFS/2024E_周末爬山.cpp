#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> grid;
vector<vector<int>> visited;
vector<pair<int, int>> v;  // 山峰高度, 步长
bool cmp1(pair<int, int>& a, pair<int, int>& b) {
    if (a.first == b.first) {
        return a.second < b.second;
    } else {
        return a.first > b.first;
    }
}

struct Peak {
    int x;
    int y;
    int step;
};
void bfs(int row, int col, queue<Peak>& q, int updown) {
    vector<int> dirX = {0, 1, 0, -1};
    vector<int> dirY = {1, 0, -1, 0};

    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        for (int k = 0; k < 4; k++) {
            int tx = x + dirX[k];
            int ty = y + dirY[k];
            if (tx >= 0 && ty >= 0 && tx < row && ty < col && visited[tx][ty] == 0 && abs(grid[tx][ty] - grid[x][y]) <= updown) {
                visited[tx][ty] = 1;
                v.emplace_back(grid[tx][ty], q.front().step + 1);
                Peak temp;
                temp.x = tx;
                temp.y = ty;
                temp.step = q.front().step + 1;
                q.push(temp);
            }
        }
        q.pop();
    }
}

int main() {
    int row, col, updown;
    cin >> row >> col >> updown;
    grid.resize(row, vector<int>(col, 0));
    visited.resize(row, vector<int>(col, 0));

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> grid[i][j];
        }
    }
    Peak start;
    queue<Peak> q;
    start.x = 0;
    start.y = 0;
    start.step = 0;
    q.push(start);
    visited[0][0] = 1;
    v.emplace_back(0, 0);

    bfs(row, col, q, updown);
    // cout << 0;
    sort(v.begin(), v.end(), cmp1);
    // for (int i = 0; i < v.size(); i++) {
    //     cout << v[i].first << " " << v[i].second << endl;
    // }
    cout << v.front().first << " " << v.front().second;
}