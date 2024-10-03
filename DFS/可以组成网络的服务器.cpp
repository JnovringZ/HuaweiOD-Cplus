#include <bits/stdc++.h>
using namespace std;
// int arr[105][105];
vector<vector<int>> arr;
vector<vector<int>> arrived;
int cnt = 1;
void dfs(int x, int y, int row, int col) {
    // 顺时针
    vector<int> dirX = {0, 1, 0, -1};
    vector<int> dirY = {1, 0, -1, 0};

    for (int k = 0; k < 4; k++) {
        int tx = x + dirX[k];
        int ty = y + dirY[k];

        // 边界检查，确保 tx 和 ty 在矩阵范围内
        if (tx >= 0 && tx < row && ty >= 0 && ty < col && arr[tx][ty] == 1 && arrived[tx][ty] == 0) {
            cnt++;
            arrived[tx][ty] = 1;
            dfs(tx, ty, row, col);
        }
    }
    return;
}

int main() {
    int row, col;
    cin >> row >> col;
    arr.resize(row, vector<int>(col));
    arrived.resize(row, vector<int>(col));
    vector<pair<int, int>> point;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) {
                point.push_back(make_pair(i, j));
            }
        }
    }

    int maxCnt = 0;
    for (int i = 0; i < point.size(); i++) {
        int x = point[i].first;
        int y = point[i].second;
        arrived[x][y] = 1;
        dfs(x, y, row, col);
        maxCnt = max(maxCnt, cnt);
        cnt = 1;
    }
    cout << maxCnt << endl;

    // for (int i = 0; i < row; i++) {
    //     for (int j = 0; j < col; j++) {
    //         // if (arr[i][j] = 1)
    //         cout << arr[i][j];
    //     }
    //     cout << endl;
    // }
}