#include <bits/stdc++.h>
using namespace std;
int grid[105][105];
int arrived[105][105] = {0};
int cnt = 1;
queue<pair<int, int>> q;
vector<int> dirX = {0, 1, 0, -1};
vector<int> dirY = {1, 0, -1, 0};

void bfs() {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;

        for (int k = 0; k < 4; k++) {
            int tx = x + dirX[k];
            int ty = y + dirY[k];
            // cout << tx << ty << endl;

            if (grid[tx][ty] == 1 && arrived[tx][ty] == 0) {
                cnt++;
                // cout << tx << " " << ty << " " << cnt << endl;
                arrived[tx][ty] = 1;
                q.push(make_pair(tx, ty));
            }
        }
        q.pop();
    }
}
int main() {
    int row, col;
    cin >> row >> col;
    vector<pair<int, int>> point;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 1) {
                point.push_back(make_pair(i, j));
            }
        }
    }

    int maxCnt = 0;
    for (int i = 0; i < point.size(); i++) {
        int x = point[i].first;
        int y = point[i].second;
        arrived[x][y] = 1;
        q.push(make_pair(x, y));
        bfs();
        maxCnt = max(maxCnt, cnt);
        cnt = 1;
    }

    cout << maxCnt;
}