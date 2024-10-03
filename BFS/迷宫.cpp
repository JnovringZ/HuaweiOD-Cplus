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
#include <bits/stdc++.h>
using namespace std;
struct Point {
    int x;
    int y;
    int step;
};

int main() {
    int row, col;
    cin >> row >> col;
    int arrived[50][50] = {0};
    int arr[100][100];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> arr[i][j];
        }
    }
    Point start;
    int startX, startY;
    int endX, endY;
    cin >> startX >> startY;
    cin >> endX >> endY;

    start.x = startX;
    start.y = startY;
    start.step = 0;
    queue<Point> q;
    q.push(start);

    bool flag = false;
    arrived[startX][startY] = 1;
    vector<int> dirX = {0, 1, 0, -1};
    vector<int> dirY = {1, 0, -1, 0};

    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        if (x == endX && y == endY) {
            flag = true;
            cout << q.front().step;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int tx = x + dirX[i];
            int ty = y + dirY[i];
            if (arr[tx][ty] == 1 && arrived[tx][ty] == 0) {
                cout << tx << ty << endl;
                Point temp;
                temp.x = tx;
                temp.y = ty;
                temp.step = q.front().step + 1;
                q.push(temp);
                arrived[tx][ty] = 1;
            }
        }
        // cout << q.front().x << q.front().y << q.front().step << endl;
        q.pop();
        // if (!flag) {
        //     cout << "no answer" << endl;
        // }
    }

    // for (int i = 0; i < 50; i++) {
    //     for (int j = 0; j < 50; j++) {
    //         cout << arrived[i][j] << endl;
    //     }
    // }
}