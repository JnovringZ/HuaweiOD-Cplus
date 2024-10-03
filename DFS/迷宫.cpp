/*
5 4
1 1 -1 1
1 1 1 1
1 1 -1 1
1 -1 1 1
1 1 1 -1
0 0
3 2
*/
/*
解释
5行4列的迷宫
1表示空地, -1表示墙壁无法到达
倒数第二行前两个数表示起点坐标
最后一行后两个数表示终点坐标
*/

#include <bits/stdc++.h>
using namespace std;
int startX, startY;
int endX, endY;
int minStep = 999999;
int row, col;
// 1表示空地, -1表示墙壁
int v[100][100];
// 1表示到来过, 0表示还未来过
int arrived[100][100] = {0};

void dfs(int x, int y, int step) {
    if (x == endX && y == endY) {
        if (step < minStep) {
            minStep = step;
            // cout << minStep;
        }
        return;
    }
    vector<int> directX = {0, 1, 0, -1};
    vector<int> directY = {1, 0, -1, 0};
    for (int count = 0; count < 4; count++) {
        int stridedX = x + directX[count];
        int stridedY = y + directY[count];

        if (v[stridedX][stridedY] == 1 && arrived[stridedX][stridedY] == 0) {
            cout << "stridedX " << stridedX << " " << "stridedY: " << stridedY << endl;
            arrived[stridedX][stridedY] = 1;
            dfs(stridedX, stridedY, step + 1);
            arrived[stridedX][stridedY] = 0;
        }
    }
    return;

    // 顺时针探索

    // 右
    // v表示地图, 1是表示空地, -1表示墙壁
    // arrived表示此块区域是否已到达;
    // if (v[x][y + 1] == 1 && arrived[x][y + 1] == 0) {
    //     cout << x << y + 1 << " " << endl;
    //     arrived[x][y + 1] = 1;
    //     dfs(x, y + 1, step + 1);
    //     arrived[x][y + 1] = 0;
    // }
    // // 下
    // if (v[x + 1][y] == 1 && arrived[x + 1][y] == 0) {
    //     cout << x + 1 << y << " " << endl;
    //     arrived[x + 1][y] = 1;
    //     dfs(x + 1, y, step + 1);
    //     arrived[x + 1][y] = 0;
    // }
    // // 左
    // if (v[x][y - 1] == 1 && arrived[x][y - 1] == 0) {
    //     cout << x << y - 1 << " " << endl;
    //     arrived[x][y - 1] = 1;
    //     dfs(x, y - 1, step + 1);
    //     arrived[x][y - 1] = 0;
    // }
    // // 上
    // if (v[x - 1][y] == 1 && arrived[x - 1][y] == 0) {
    //     cout << x - 1 << y << " " << endl;
    //     arrived[x - 1][y] = 1;
    //     dfs(x - 1, y, step + 1);
    //     arrived[x - 1][y] = 0;
    // }
    // return;
}
int main() {
    cin >> row >> col;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> v[i][j];
        }
    }

    cin >> startX >> startY;
    cin >> endX >> endY;

    // arrived[startX][startY] = 1;
    // dfs(startX, startY, 0);
    // cout << minStep << endl;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            cout << arrived[i][j] << endl;
        }
    }
}
